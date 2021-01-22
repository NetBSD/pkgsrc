# $NetBSD: hacks.mk,v 1.3 2021/01/22 17:16:45 schmonz Exp $

# s6 TLS tools don't use OpenSSL, but do need to know where to find CA
# certs. Buildlink just enough OpenSSL to read ${SSLCERTS}.
PKG_HACKS+=	detect-openssl-cadir

BUILDLINK_INCDIRS.openssl=	/nonexistent
BUILDLINK_LIBDIRS.openssl=	/nonexistent
BUILDLINK_DEPMETHOD.openssl=	build
.include "../../security/openssl/buildlink3.mk"
