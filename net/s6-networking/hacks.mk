# $NetBSD: hacks.mk,v 1.4 2025/06/04 13:29:32 schmonz Exp $

# s6 TLS tools don't necessarily use OpenSSL, but do need to know where to find CA
# certs. Buildlink just enough OpenSSL to read ${SSLCERTS}.
PKG_HACKS+=	detect-openssl-cadir

BUILDLINK_INCDIRS.openssl=	/nonexistent
BUILDLINK_LIBDIRS.openssl=	/nonexistent
BUILDLINK_DEPMETHOD.openssl=	build
.include "../../security/openssl/buildlink3.mk"
