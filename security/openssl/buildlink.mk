# $NetBSD: buildlink.mk,v 1.6 2001/07/18 18:03:16 jlam Exp $
#
# This Makefile fragment is included by packages that use OpenSSL.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define USE_OPENSSL_096 to require openssl>=0.9.6.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(OPENSSL_BUILDLINK_MK)
OPENSSL_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

# Check for a usable installed version of OpenSSL.  Version must be greater
# than 0.9.5a.  If a usable version isn't present, then use the pkgsrc
# OpenSSL package.
#
.include "../../mk/bsd.prefs.mk"
_NEED_OPENSSL=		YES
.if exists(/usr/include/openssl/opensslv.h)
_OPENSSLV_H=		/usr/include/openssl/opensslv.h
_OPENSSL_VERSION!=	${AWK} '/.*OPENSSL_VERSION_NUMBER.*/ { print $$3 }' \
				${_OPENSSLV_H}
BUILDLINK_DEPENDS.openssl=	{openssl-0.9.5a,openssl>=0.9.6}
_VALID_SSL_VERSIONS=		0x0090581fL
.if defined(USE_OPENSSL_096)
BUILDLINK_DEPENDS.openssl=	openssl>=0.9.6
_VALID_SSL_VERSIONS=		0x0090600fL
.else
_VALID_SSL_VERSIONS+=		0x0090600fL
.endif
_VALID_SSL_VERSIONS+=		0x0090601fL
_VALID_SSL_VERSIONS+=		0x0090602fL

.for PATTERN in ${_VALID_SSL_VERSIONS}
.if ${_OPENSSL_VERSION:M${PATTERN}} != ""
_NEED_OPENSSL=		NO
.endif
.endfor
.endif

.if ${_NEED_OPENSSL} == "YES"
DEPENDS+=	${BUILDLINK_DEPENDS.openssl}:../../security/openssl
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

.if defined(USE_RSAREF2) && ${USE_RSAREF2} == YES
.include "../../security/rsaref/buildlink.mk"
.endif

BUILDLINK_TARGETS.openssl=	openssl-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.openssl}

pre-configure: ${BUILDLINK_TARGETS.openssl}
openssl-buildlink: _BUILDLINK_USE

.endif	# OPENSSL_BUILDLINK_MK
