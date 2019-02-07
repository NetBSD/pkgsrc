$NetBSD: patch-src_support_FileName.cpp,v 1.1 2019/02/07 10:42:48 markd Exp $

Changeset 3a123b90.
Fix build with boost 1.69 (bug 11349).

--- src/support/FileName.cpp.orig	2018-12-09 20:04:52.000000000 +0000
+++ src/support/FileName.cpp
@@ -67,15 +67,6 @@
 using namespace std;
 using namespace lyx::support;
 
-// OK, this is ugly, but it is the only workaround I found to compile
-// with gcc (any version) on a system which uses a non-GNU toolchain.
-// The problem is that gcc uses a weak symbol for a particular
-// instantiation and that the system linker usually does not
-// understand those weak symbols (seen on HP-UX, tru64, AIX and
-// others). Thus we force an explicit instanciation of this particular
-// template (JMarc)
-template struct boost::detail::crc_table_t<32, 0x04C11DB7, true>;
-
 namespace lyx {
 namespace support {
 
