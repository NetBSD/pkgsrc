# $NetBSD: buildlink.mk,v 1.1 2001/06/18 05:30:20 jlam Exp $
#
# This Makefile fragment is included by packages that use OpenSSL.
#
# To use this Makefile fragment, simply:
#
# (1) Include this Makefile fragment in the package Makefile,
# (2) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (3) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(OPENSSL_BUILDLINK_MK)
OPENSSL_BUILDLINK_MK=	# defined

.include "../../mk/bsd.prefs.mk"

OPENSSL_REQD=		0.9.[56]*

.if exists(/usr/include/openssl/ssl.h)
_NEED_OPENSSL=		NO
.else
_NEED_OPENSSL=		YES
.endif

.if ${_NEED_OPENSSL} == "YES"
DEPENDS+=			openssl-${OPENSSL_REQD}:../../security/openssl
BUILDLINK_PREFIX.openssl=	${LOCALBASE}
SSLBASE=			${LOCALBASE}
SSLCERTS=			${SSLBASE}/certs
.else
BUILDLINK_PREFIX.openssl=	/usr
SSLBASE=			/usr
SSLCERTS=			/etc/openssl/certs
.endif
BUILD_DEFS+=			SSLBASE SSLCERTS

BUILDLINK_FILES.openssl=	include/openssl/*
BUILDLINK_FILES.openssl+=	lib/libRSAglue.*
BUILDLINK_FILES.openssl+=	lib/libcrypto.*
BUILDLINK_FILES.openssl+=	lib/libssl.*

BUILDLINK_TARGETS.openssl=	openssl-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.openssl}

pre-configure: ${BUILDLINK_TARGETS.openssl}
openssl-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# OPENSSL_BUILDLINK_MK
