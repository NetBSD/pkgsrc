$NetBSD: patch-src_devices_machine_netlist.cpp,v 1.1 2017/01/04 23:05:12 wiz Exp $

unsigned int * vs. uint8_t *

--- src/devices/machine/netlist.cpp.orig	2016-12-27 21:02:43.000000000 +0000
+++ src/devices/machine/netlist.cpp
@@ -216,7 +216,7 @@ void netlist_mame_rom_t::device_start()
 	if (memregion(m_data_tag) != nullptr)
 		m_data = memregion(m_data_tag)->base();
 
-	m_param->setTo(m_data);
+	m_param->setTo((unsigned int *)m_data);
 }
 
 // ----------------------------------------------------------------------------------------
@@ -249,7 +249,7 @@ void netlist_ram_pointer_t::device_start
 		fatalerror("device %s wrong parameter type for %s\n", basetag(), m_param_name.cstr());
 	}
 
-	m_data = (*m_param)();
+	m_data = (unsigned char *)(*m_param)();
 }
 
 // ----------------------------------------------------------------------------------------
