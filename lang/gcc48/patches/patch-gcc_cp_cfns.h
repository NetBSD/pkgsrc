$NetBSD: patch-gcc_cp_cfns.h,v 1.1 2018/06/27 10:07:08 maya Exp $

Backport upstream commit to fix build with newer GCC

 2016-02-19 Jakub Jelinek <jakub@redhat.com>

            Bernd Edlinger  <bernd.edlinger@hotmail.de>

        * Make-lang.in: Invoke gperf with -L C++.
        * cfns.gperf: Remove prototypes for hash and libc_name_p
        inlines.
        * cfns.h: Regenerated.
        * except.c (nothrow_libfn_p): Adjust.

--- gcc/cp/cfns.h.orig	2013-01-10 20:38:27.000000000 +0000
+++ gcc/cp/cfns.h
@@ -1,5 +1,5 @@
-/* ANSI-C code produced by gperf version 3.0.3 */
-/* Command-line: gperf -o -C -E -k '1-6,$' -j1 -D -N libc_name_p -L ANSI-C cfns.gperf  */
+/* C++ code produced by gperf version 3.0.4 */
+/* Command-line: gperf -o -C -E -k '1-6,$' -j1 -D -N libc_name_p -L C++ --output-file cfns.h cfns.gperf  */
 
 #if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
       && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
@@ -28,7 +28,7 @@
 #error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
 #endif
 
-#line 1 "cfns.gperf"
+#line 3 "cfns.gperf"
 
 /* Copyright (C) 2000-2013 Free Software Foundation, Inc.
 
@@ -47,25 +47,18 @@ for more details.
 You should have received a copy of the GNU General Public License
 along with GCC; see the file COPYING3.  If not see
 <http://www.gnu.org/licenses/>.  */
-#ifdef __GNUC__
-__inline
-#endif
-static unsigned int hash (const char *, unsigned int);
-#ifdef __GNUC__
-__inline
-#endif
-const char * libc_name_p (const char *, unsigned int);
 /* maximum key range = 391, duplicates = 0 */
 
-#ifdef __GNUC__
-__inline
-#else
-#ifdef __cplusplus
-inline
-#endif
-#endif
-static unsigned int
-hash (register const char *str, register unsigned int len)
+class libc_name
+{
+private:
+  static inline unsigned int hash (const char *str, unsigned int len);
+public:
+  static const char *libc_name_p (const char *str, unsigned int len);
+};
+
+inline unsigned int
+libc_name::hash (register const char *str, register unsigned int len)
 {
   static const unsigned short asso_values[] =
     {
@@ -122,14 +115,8 @@ hash (register const char *str, register
   return hval + asso_values[(unsigned char)str[len - 1]];
 }
 
-#ifdef __GNUC__
-__inline
-#ifdef __GNUC_STDC_INLINE__
-__attribute__ ((__gnu_inline__))
-#endif
-#endif
 const char *
-libc_name_p (register const char *str, register unsigned int len)
+libc_name::libc_name_p (register const char *str, register unsigned int len)
 {
   enum
     {
