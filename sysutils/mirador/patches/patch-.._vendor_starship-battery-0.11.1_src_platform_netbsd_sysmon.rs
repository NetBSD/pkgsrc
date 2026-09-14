$NetBSD: patch-.._vendor_starship-battery-0.11.1_src_platform_netbsd_sysmon.rs,v 1.1 2026/09/14 12:14:18 pin Exp $

Fix battery readout using upstreams pull request.
https://github.com/starship/rust-battery/pull/168

--- ../vendor/starship-battery-0.11.1/src/platform/netbsd/sysmon.rs.orig	2026-09-14 11:26:29.446107617 +0000
+++ ../vendor/starship-battery-0.11.1/src/platform/netbsd/sysmon.rs
@@ -1,3 +1,4 @@
+use std::ffi::CStr;
 use std::fs;
 use std::os::fd::AsRawFd;
 use std::ptr::{addr_of_mut, null_mut, NonNull};
@@ -49,9 +50,9 @@ pub fn get_system_envsys_plist() -> Result<plist::Dict
         return Err(Error::invalid_data("Invalid result of EnvSys ioctl"));
     }
 
-    let dict = plist::from_bytes(unsafe {
+    let dict = parse_envsys_plist(unsafe {
         slice::from_raw_parts(plist_ref.pref_plist, plist_ref.pref_len)
-    })?;
+    });
 
     unsafe {
         // The netbsd libprop says ioctl returned mmap'ed memory that must be munmap'ed.
@@ -64,5 +65,55 @@ pub fn get_system_envsys_plist() -> Result<plist::Dict
         )?;
     }
 
-    Ok(dict)
+    dict
+}
+
+/// Parse the XML plist the kernel hands back through `ENVSYS_GETDICTIONARY`.
+///
+/// libprop externalizes the dictionary as a C string and reports its length
+/// *including* the terminating NUL (`pref_len = strlen(buf) + 1`, see
+/// `common/lib/libprop/prop_kern.c`). Since plist 1.7.4 the XML reader
+/// rejects any non-whitespace after the closing `</plist>`, so the buffer is
+/// read as the C string it is, or every battery on NetBSD reads as
+/// "Problem while processing plist". A buffer with no NUL is parsed whole.
+fn parse_envsys_plist(bytes: &[u8]) -> Result<plist::Dictionary, Error> {
+    let document = CStr::from_bytes_until_nul(bytes).map_or(bytes, CStr::to_bytes);
+    Ok(plist::from_bytes(document)?)
+}
+
+#[cfg(test)]
+mod tests {
+    use super::parse_envsys_plist;
+
+    const ENVSYS: &str = concat!(
+        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n",
+        "<!DOCTYPE plist PUBLIC \"-//Apple Computer//DTD PLIST 1.0//EN\" ",
+        "\"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n",
+        "<plist version=\"1.0\">\n<dict>\n\t<key>acpibat0</key>\n\t<array>\n",
+        "\t\t<dict>\n\t\t\t<key>cur-value</key>\n\t\t\t<integer>1</integer>\n",
+        "\t\t\t<key>description</key>\n\t\t\t<string>present</string>\n",
+        "\t\t\t<key>state</key>\n\t\t\t<string>valid</string>\n",
+        "\t\t\t<key>type</key>\n\t\t\t<string>Indicator</string>\n\t\t</dict>\n",
+        "\t</array>\n</dict>\n</plist>\n"
+    );
+
+    #[test]
+    fn the_kernels_trailing_nul_is_not_part_of_the_document() {
+        let mut bytes = ENVSYS.as_bytes().to_vec();
+        bytes.push(0);
+        let dict = parse_envsys_plist(&bytes).expect("a NUL-terminated envsys plist parses");
+        assert!(dict.contains_key("acpibat0"));
+    }
+
+    #[test]
+    fn a_plist_without_the_nul_still_parses() {
+        let dict = parse_envsys_plist(ENVSYS.as_bytes()).expect("parses");
+        assert!(dict.contains_key("acpibat0"));
+    }
+
+    #[test]
+    fn only_nuls_is_an_error_not_a_panic() {
+        assert!(parse_envsys_plist(&[0, 0]).is_err());
+        assert!(parse_envsys_plist(&[]).is_err());
+    }
 }
