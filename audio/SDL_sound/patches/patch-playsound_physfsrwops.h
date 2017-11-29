$NetBSD: patch-playsound_physfsrwops.h,v 1.1 2017/11/29 12:42:54 wiz Exp $

Remove undefined __EXPORT__ keyword.

--- playsound/physfsrwops.h.orig	2008-04-17 17:56:21.000000000 +0000
+++ playsound/physfsrwops.h
@@ -39,7 +39,7 @@ extern "C" {
  *  @return A valid SDL_RWops structure on success, NULL on error. Specifics
  *           of the error can be gleaned from PHYSFS_getLastError().
  */
-__EXPORT__ SDL_RWops *PHYSFSRWOPS_openRead(const char *fname);
+SDL_RWops *PHYSFSRWOPS_openRead(const char *fname);
 
 /**
  * Open a platform-independent filename for writing, and make it accessible
@@ -51,7 +51,7 @@ __EXPORT__ SDL_RWops *PHYSFSRWOPS_openRe
  *  @return A valid SDL_RWops structure on success, NULL on error. Specifics
  *           of the error can be gleaned from PHYSFS_getLastError().
  */
-__EXPORT__ SDL_RWops *PHYSFSRWOPS_openWrite(const char *fname);
+SDL_RWops *PHYSFSRWOPS_openWrite(const char *fname);
 
 /**
  * Open a platform-independent filename for appending, and make it accessible
@@ -63,7 +63,7 @@ __EXPORT__ SDL_RWops *PHYSFSRWOPS_openWr
  *  @return A valid SDL_RWops structure on success, NULL on error. Specifics
  *           of the error can be gleaned from PHYSFS_getLastError().
  */
-__EXPORT__ SDL_RWops *PHYSFSRWOPS_openAppend(const char *fname);
+SDL_RWops *PHYSFSRWOPS_openAppend(const char *fname);
 
 /**
  * Make a SDL_RWops from an existing PhysicsFS file handle. You should
@@ -75,7 +75,7 @@ __EXPORT__ SDL_RWops *PHYSFSRWOPS_openAp
  *  @return A valid SDL_RWops structure on success, NULL on error. Specifics
  *           of the error can be gleaned from PHYSFS_getLastError().
  */
-__EXPORT__ SDL_RWops *PHYSFSRWOPS_makeRWops(PHYSFS_file *handle);
+SDL_RWops *PHYSFSRWOPS_makeRWops(PHYSFS_file *handle);
 
 #ifdef __cplusplus
 }
