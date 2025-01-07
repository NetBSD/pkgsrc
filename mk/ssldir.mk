#	$NetBSD: ssldir.mk,v 1.1 2025/01/07 19:18:07 riastradh Exp $

# used by ssl.mk
# used by ../security/openssl/builtin.mk
#
# Packages should not include this file directly.  Instead, they should
# include either security/openssl/buildlink3.mk or mk/ssl.mk.

.include "bsd.fast.prefs.mk"

.if ${OPSYS} == "NetBSD"
SSLDIR=	/etc/openssl
.elif ${OPSYS} == "Linux"
.  if exists(${_CROSS_DESTDIR:U}/etc/pki/tls)
# Some distributions have moved to /etc/pki/tls, with incomplete
# symlinks from /etc/ssl.  Prefer the new location if it exists
SSLDIR=	/etc/pki/tls
.  else
SSLDIR=	/etc/ssl 		# standard location
.  endif
.elif ${OPSYS} == "Haiku"
.  if exists(${_CROSS_DESTDIR:U}/boot/system/data/ssl)
SSLDIR=	/boot/system/data/ssl
.  else
SSLDIR=	/boot/common/data/ssl
.  endif
.else
SSLDIR=	/etc/ssl 		# most likely place
.endif
