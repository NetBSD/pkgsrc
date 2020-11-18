$NetBSD: patch-Modules___zoneinfo.c,v 1.1 2020/11/18 12:18:29 sjmulder Exp $

Move `#pragma GCC diagnostics` outside function for GCC 4.4.

--- Modules/_zoneinfo.c.orig	2020-10-05 15:07:58.000000000 +0000
+++ Modules/_zoneinfo.c
@@ -1197,6 +1197,19 @@ calendarrule_year_to_timestamp(Transitio
             (int64_t)(self->minute * 60) + (int64_t)(self->second));
 }
 
+// Re. `if (day < 0 || day > 6)`:
+//
+// day is an unsigned integer, so day < 0 should always return false, but
+// if day's type changes to a signed integer *without* changing this value,
+// it may create a bug. Considering that the compiler should be able to
+// optimize out the first comparison if day is an unsigned integer anyway,
+// we will leave this comparison in place and disable the compiler warning.
+//
+// Old GCC versions like 4.4 don't allow `#pragma GCC diagnostic` inside
+// functions.
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wtype-limits"
+
 /* Constructor for CalendarRule. */
 int
 calendarrule_new(uint8_t month, uint8_t week, uint8_t day, int8_t hour,
@@ -1219,15 +1232,7 @@ calendarrule_new(uint8_t month, uint8_t 
         return -1;
     }
 
-    // day is an unsigned integer, so day < 0 should always return false, but
-    // if day's type changes to a signed integer *without* changing this value,
-    // it may create a bug. Considering that the compiler should be able to
-    // optimize out the first comparison if day is an unsigned integer anyway,
-    // we will leave this comparison in place and disable the compiler warning.
-#pragma GCC diagnostic push
-#pragma GCC diagnostic ignored "-Wtype-limits"
     if (day < 0 || day > 6) {
-#pragma GCC diagnostic pop
         PyErr_Format(PyExc_ValueError, "Day must be in [0, 6]");
         return -1;
     }
@@ -1247,6 +1252,7 @@ calendarrule_new(uint8_t month, uint8_t 
     *out = new_offset;
     return 0;
 }
+#pragma GCC diagnostic pop
 
 /* Function to calculate the local timestamp of a transition from the year.
  *
