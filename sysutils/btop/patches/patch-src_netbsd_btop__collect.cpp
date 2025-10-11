$NetBSD: patch-src_netbsd_btop__collect.cpp,v 1.1 2025/10/11 09:29:30 wiz Exp $

Bugfixes and improvements from RVP in PR 59702.

--- src/netbsd/btop_collect.cpp.orig	2025-09-19 20:29:22.000000000 +0000
+++ src/netbsd/btop_collect.cpp
@@ -52,6 +52,7 @@ tab-size = 4
 #include <kvm.h>
 #include <paths.h>
 #include <fcntl.h>
+#include <regex.h>
 #include <unistd.h>
 #include <uvm/uvm_extern.h>
 
@@ -220,12 +221,12 @@ namespace Cpu {
 		prop_object_t fields_array;
 		// List of common thermal sensors in NetBSD.
 		const string sensors[6] = {
-			"acpitz0",
-			"acpitz1",
 			"coretemp0",
-			"coretemp1",
+			"acpitz0",
 			"thinkpad0",
-			"amdzentemp0"
+			"amdzentemp0",
+			"coretemp1",
+			"acpitz1"
 		};
 
 		int fd = open(_PATH_SYSMON, O_RDONLY);
@@ -242,10 +243,9 @@ namespace Cpu {
 			return got_sensors;
 		}
 
+		close(fd);
+
 		if (prop_dictionary_count(dict) == 0) {
-			if (fd != -1) {
-				close(fd);
-			}
 			Logger::warning("no drivers registered for envsys");
 			return got_sensors;
 		}
@@ -261,15 +261,13 @@ namespace Cpu {
 			}
 		}
 		if (prop_object_type(fields_array) != PROP_TYPE_ARRAY) {
-			if (fd != -1) {
-				close(fd);
-			}
 			return got_sensors;
 		}
 
 		if (Config::getB("show_coretemp") and Config::getB("check_temp")) {
 			got_sensors = true;
 		}
+
 		return got_sensors;
 	}
 
@@ -294,32 +292,32 @@ namespace Cpu {
 			return;
 		}
 
+		close(fd);
+
 		if (prop_dictionary_count(dict) == 0) {
-			if (fd != -1) {
-				close(fd);
-			}
 			Logger::warning("no drivers registered for envsys");
 			return;
 		}
 
 		prop_object_t fields_array = prop_dictionary_get(prop_dictionary_t(dict), Cpu::cpu_sensor.c_str());
 		if (prop_object_type(fields_array) != PROP_TYPE_ARRAY) {
-			if (fd != -1) {
-				close(fd);
-			}
 			Logger::warning("unknown device " + Cpu::cpu_sensor);
 			return;
 		}
 
 		prop_object_iterator_t fields_iter = prop_array_iterator(prop_array_t(fields_array));
 		if (fields_iter == NULL) {
-			if (fd != -1) {
-				close(fd);
-			}
 			return;
 		}
 
+		regex_t r;
+		if (regcomp(&r, "(cpu[0-9]* )*temperature", REG_EXTENDED)) {
+			Logger::warning("regcomp() failed");
+			return;
+		}
+		
 		string prop_description = "no description";
+		char buf[64];
 		while ((fields = (prop_dictionary_t) prop_object_iterator_next(prop_object_iterator_t(fields_iter))) != NULL) {
 			props = (prop_dictionary_t) prop_dictionary_get(fields, "device-properties");
 			if (props != NULL) continue;
@@ -333,16 +331,19 @@ namespace Cpu {
 			}
 
 
-			prop_description = prop_string_cstring(prop_string_t(description));
+			prop_string_copy_value(prop_string_t(description), buf, sizeof buf);
+			prop_description = buf;
 
-			if (prop_description == "temperature") {
-				current_temp = prop_number_integer_value(prop_number_t(cur_value));
+			if (regexec(&r, prop_description.c_str(), 0, NULL, 0) == 0) {
+				current_temp = prop_number_signed_value(prop_number_t(cur_value));
 				if (max_value != NULL) {
-					current_cpu.temp_max = MUKTOC(prop_number_integer_value(prop_number_t(max_value)));
+					current_cpu.temp_max = MUKTOC(prop_number_signed_value(prop_number_t(max_value)));
 				}
 			}
 		}
 
+		regfree(&r);
+
 		prop_object_iterator_release(fields_iter);
 		prop_object_release(dict);
 
@@ -441,10 +442,9 @@ namespace Cpu {
 			return {0, 0.0, 0, ""};
 		}
 
+		close(fd);
+
 		if (prop_dictionary_count(dict) == 0) {
-			if (fd != -1) {
-				close(fd);
-			}
 			has_battery = false;
 			Logger::warning("no drivers registered for envsys");
 			return {0, 0.0, 0, ""};
@@ -452,9 +452,6 @@ namespace Cpu {
 
 		prop_object_t fields_array = prop_dictionary_get(prop_dictionary_t(dict), "acpibat0");
 		if (prop_object_type(fields_array) != PROP_TYPE_ARRAY) {
-			if (fd != -1) {
-				close(fd);
-			}
 			has_battery = false;
 			Logger::warning("unknown device 'acpibat0'");
 			return {0, 0.0, 0, ""};
@@ -462,9 +459,6 @@ namespace Cpu {
 
 		prop_object_iterator_t fields_iter = prop_array_iterator(prop_array_t(fields_array));
 		if (fields_iter == NULL) {
-			if (fd != -1) {
-				close(fd);
-			}
 			has_battery = false;
 			return {0, 0.0, 0, ""};
 		}
@@ -476,6 +470,7 @@ namespace Cpu {
 		int64_t max_charge = 0;
 		string status = "unknown";
 		string prop_description = "no description";
+		char buf[64];
 
 		while ((fields = (prop_dictionary_t) prop_object_iterator_next(prop_object_iterator_t(fields_iter))) != NULL) {
 			props = (prop_dictionary_t) prop_dictionary_get(fields, "device-properties");
@@ -490,23 +485,26 @@ namespace Cpu {
 			}
 
 
-			prop_description = prop_string_cstring(prop_string_t(description));
+			prop_string_copy_value(prop_string_t(description), buf, sizeof buf);
+			prop_description = buf;
 
 			if (prop_description == "charge") {
 				if (max_value == NULL) {
 					continue;
 				}
-				cur_charge = prop_number_integer_value(prop_number_t(cur_value));
-				max_charge = prop_number_integer_value(prop_number_t(max_value));
+				cur_charge = prop_number_signed_value(prop_number_t(cur_value));
+				max_charge = prop_number_signed_value(prop_number_t(max_value));
 			}
 
 			if (prop_description == "present") {
-				is_present = prop_number_integer_value(prop_number_t(cur_value));
+				is_present = prop_number_signed_value(prop_number_t(cur_value));
 			}
 
 			if (prop_description == "charging") {
 				status = prop_description;
-				string charging_type = prop_string_cstring(prop_string_t(prop_dictionary_get(fields, "type")));
+				char buf[64];
+				prop_string_copy_value(prop_string_t(prop_dictionary_get(fields, "type")), buf, sizeof buf);
+				string charging_type = buf;
 				is_battery = charging_type == "Battery charge" ? true : false;
 			}
 
