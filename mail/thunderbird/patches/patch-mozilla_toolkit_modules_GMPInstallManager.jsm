$NetBSD: patch-mozilla_toolkit_modules_GMPInstallManager.jsm,v 1.1 2015/07/09 15:17:34 ryoon Exp $

--- mozilla/toolkit/modules/GMPInstallManager.jsm.orig	2015-06-08 17:49:31.000000000 +0000
+++ mozilla/toolkit/modules/GMPInstallManager.jsm
@@ -874,9 +874,7 @@ GMPDownloader.prototype = {
       let gmpAddon = this._gmpAddon;
       let installToDirPath = Cc["@mozilla.org/file/local;1"].
                           createInstance(Ci.nsIFile);
-      let path = OS.Path.join(OS.Constants.Path.profileDir,
-                              gmpAddon.id,
-                              gmpAddon.version);
+      let path = OS.Path.join(OS.Constants.Path.profileDir, gmpAddon.id);
       installToDirPath.initWithPath(path);
       log.info("install to directory path: " + installToDirPath.path);
       let gmpInstaller = new GMPExtractor(zipPath, installToDirPath.path);
@@ -885,10 +883,12 @@ GMPDownloader.prototype = {
         // Success, set the prefs
         let now = Math.round(Date.now() / 1000);
         GMPPrefs.set(GMPPrefs.KEY_PLUGIN_LAST_UPDATE, now, gmpAddon.id);
-        // Setting the version pref signals installation completion to consumers,
-        // if you need to set other prefs etc. do it before this.
+        // Setting the path pref signals installation completion to consumers,
+        // so set the version and potential other information they use first.
         GMPPrefs.set(GMPPrefs.KEY_PLUGIN_VERSION, gmpAddon.version,
                      gmpAddon.id);
+        GMPPrefs.set(GMPPrefs.KEY_PLUGIN_PATH,
+                     installToDirPath.path, gmpAddon.id);
         this._deferred.resolve(extractedPaths);
       }, err => {
         this._deferred.reject(err);
