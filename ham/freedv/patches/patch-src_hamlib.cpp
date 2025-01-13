$NetBSD: patch-src_hamlib.cpp,v 1.2 2025/01/13 23:02:50 gdt Exp $

Hunks 1, 2:
hamlib 4.6 has an API break and freedv has not adapted
https://github.com/drowe67/freedv-gui/issues/806

Hunk 3:
Fix semi-obvious use of wrong constant.  Perhaps hamlib has prefixed the
constant to avoid collisions, since this freedv release.  Not reported
upstream because the package is not up to date.
 
--- src/hamlib.cpp.orig	2020-07-18 23:16:05.000000000 +0000
+++ src/hamlib.cpp
@@ -29,7 +29,7 @@ using namespace std;
 typedef std::vector<const struct rig_caps *> riglist_t;
 
 static bool rig_cmp(const struct rig_caps *rig1, const struct rig_caps *rig2);
-static int build_list(const struct rig_caps *rig, rig_ptr_t);
+static int build_list(struct rig_caps *rig, rig_ptr_t);
 
 Hamlib::Hamlib() : 
     m_rig(NULL),
@@ -55,7 +55,7 @@ Hamlib::~Hamlib() {
 		close();
 }
 
-static int build_list(const struct rig_caps *rig, rig_ptr_t rigList) {
+static int build_list(struct rig_caps *rig, rig_ptr_t rigList) {
     ((riglist_t *)rigList)->push_back(rig); 
     return 1;
 }
@@ -114,7 +114,7 @@ bool Hamlib::connect(unsigned int rig_in
 
     /* TODO we may also need civaddr for Icom */
 
-    strncpy(m_rig->state.rigport.pathname, serial_port, FILPATHLEN - 1);
+    strncpy(m_rig->state.rigport.pathname, serial_port, HAMLIB_FILPATHLEN - 1);
     if (serial_rate) {
         fprintf(stderr, "hamlib: setting serial rate: %d\n", serial_rate);
         m_rig->state.rigport.parm.serial.rate = serial_rate;
