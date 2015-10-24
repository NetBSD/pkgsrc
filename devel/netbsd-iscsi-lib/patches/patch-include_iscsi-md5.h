$NetBSD: patch-include_iscsi-md5.h,v 1.1.2.2 2015/10/24 19:25:36 bsiegert Exp $

--- include/iscsi-md5.h.orig	2009-07-02 09:12:23.000000000 +0000
+++ include/iscsi-md5.h
@@ -29,8 +29,8 @@
  * documentation and/or software.
  */
 
-#ifndef _SYS_MD5_H_
-#define _SYS_MD5_H_
+#ifndef ISCSI_MD5_H
+#define ISCSI_MD5_H
 
 #include <sys/types.h>
 
@@ -49,15 +49,17 @@ typedef struct iSCSI_MD5Context {
 	unsigned char buffer[64]; /* input buffer */
 } iSCSI_MD5_CTX;
 
-__BEGIN_DECLS
+#ifdef __cplusplus
+extern "C" {
+#endif
 void	iSCSI_MD5Init(iSCSI_MD5_CTX *);
 void	iSCSI_MD5Update(iSCSI_MD5_CTX *, const uint8_t *, size_t);
 void	iSCSI_MD5Final(unsigned char[16], iSCSI_MD5_CTX *);
-#ifndef _KERNEL
 char	*iSCSI_MD5End(iSCSI_MD5_CTX *, char *);
 char	*iSCSI_MD5File(const char *, char *);
 char	*iSCSI_MD5Data(const uint8_t *, size_t, char *);
-#endif /* _KERNEL */
-__END_DECLS
+#ifdef __cplusplus
+}
+#endif
 
-#endif /* _SYS_MD5_H_ */
+#endif /* ISCSI_MD5_H */
