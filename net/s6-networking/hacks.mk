# $NetBSD: hacks.mk,v 1.1 2020/11/24 08:33:12 schmonz Exp $

# s6 TLS tools don't use OpenSSL, but do need to know where to find CA
# certs. Buildlink just enough OpenSSL to read SSLDIR.
PKG_HACKS+=     detect-openssl-cadir

BUILDLINK_INCDIRS.openssl=	/nonexistent
BUILDLINK_LIBDIRS.openssl=	/nonexistent
BUILDLINK_DEPMETHOD.openssl=    build
.include "../../security/openssl/buildlink3.mk"
