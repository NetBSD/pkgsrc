$NetBSD: patch-lib_isc_time.c,v 1.2 2023/02/08 00:13:44 taca Exp $

* More check time_t range.

--- lib/isc/time.c.orig	2023-01-12 22:21:15.270402532 +0000
+++ lib/isc/time.c
@@ -318,7 +318,7 @@ isc_time_seconds(const isc_time_t *t) {
 
 isc_result_t
 isc_time_secondsastimet(const isc_time_t *t, time_t *secondsp) {
-	time_t seconds;
+	time_t seconds, i;
 
 	REQUIRE(t != NULL);
 	INSIST(t->nanoseconds < NS_PER_SEC);
@@ -345,7 +345,18 @@ isc_time_secondsastimet(const isc_time_t
 	INSIST(sizeof(unsigned int) == sizeof(uint32_t));
 	INSIST(sizeof(time_t) >= sizeof(uint32_t));
 
-	if (t->seconds > (~0U >> 1) && seconds <= (time_t)(~0U >> 1)) {
+	if (sizeof(time_t) == sizeof(uint32_t) &&	       /* Same size. */
+	    (time_t)0.5 != 0.5 &&	       /* Not a floating point type. */
+	    (i = (time_t)-1) != 4294967295u &&		       /* Is signed. */
+	    (seconds &
+	     (1ULL << (sizeof(time_t) * CHAR_BIT - 1))) != 0ULL) {   /* Negative. */
+		/*
+		 * This UNUSED() is here to shut up the IRIX compiler:
+		 *	variable "i" was set but never used
+		 * when the value of i *was* used in the third test.
+		 * (Let's hope the compiler got the actual test right.)
+		 */
+		UNUSED(i);
 		return (ISC_R_RANGE);
 	}
 
