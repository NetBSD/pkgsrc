# $NetBSD: buildlink.mk,v 1.12 2002/06/16 12:26:43 tron Exp $
#
# This Makefile fragment is included by packages that use OpenSSL.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define USE_OPENSSL_VERSION to the mininum OpenSSL version
#     number in <openssl/opensslv.h>, i.e. 0x0090600fL, etc.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(OPENSSL_BUILDLINK_MK)
OPENSSL_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

# OpenSSL version numbers from <openssl/opensslv.h>
OPENSSL_VERSION_095A=		0x0090581fL
OPENSSL_VERSION_096=		0x0090600fL
OPENSSL_VERSION_096A=		0x0090601fL
OPENSSL_VERSION_096B=		0x0090602fL
OPENSSL_VERSION_096D=		0x0090604fL

# Check for a usable installed version of OpenSSL.  Version must be greater
# than 0.9.5a.  If a usable version isn't present, then use the pkgsrc
# OpenSSL package.
#
.include "../../mk/bsd.prefs.mk"
USE_OPENSSL_VERSION?=		${OPENSSL_VERSION_095A}

# Associate OpenSSL dependency with version number.
.if ${USE_OPENSSL_VERSION} == ${OPENSSL_VERSION_095A}
BUILDLINK_DEPENDS.openssl=	{openssl-0.9.5a,openssl>=0.9.6}
.else
BUILDLINK_DEPENDS.openssl=	openssl>=0.9.6
.endif

_NEED_OPENSSL=		YES
.if ${OPSYS} == "Darwin"
_OPENSSLV_H=		/usr/local/include/openssl/opensslv.h
.else
_OPENSSLV_H=		/usr/include/openssl/opensslv.h
.endif
.if exists(${_OPENSSLV_H})
_OPENSSL_VERSION!=	${AWK} '/.*OPENSSL_VERSION_NUMBER.*/ { print $$3 }' \
				${_OPENSSLV_H}

_VALID_SSL_VERSIONS=	${OPENSSL_VERSION_095A}

.if ${USE_OPENSSL_VERSION} == ${OPENSSL_VERSION_096}	# OpenSSL 0.9.6
_VALID_SSL_VERSIONS=	${OPENSSL_VERSION_096}
.else
_VALID_SSL_VERSIONS+=	${OPENSSL_VERSION_096}
.endif

.if ${USE_OPENSSL_VERSION} == ${OPENSSL_VERSION_096A}	# OpenSSL 0.9.6a
_VALID_SSL_VERSIONS=	${OPENSSL_VERSION_096A}
.else
_VALID_SSL_VERSIONS+=	${OPENSSL_VERSION_096A}
.endif

.if ${USE_OPENSSL_VERSION} == ${OPENSSL_VERSION_096B}	# OpenSSL 0.9.6b
_VALID_SSL_VERSIONS=	${OPENSSL_VERSION_096B}
.else
_VALID_SSL_VERSIONS+=	${OPENSSL_VERSION_096B}
.endif

.if ${USE_OPENSSL_VERSION} == ${OPENSSL_VERSION_096D}	# OpenSSL 0.9.6d
_VALID_SSL_VERSIONS=	${OPENSSL_VERSION_096D}
.else
_VALID_SSL_VERSIONS+=	${OPENSSL_VERSION_096D}
.endif

.for PATTERN in ${_VALID_SSL_VERSIONS}
.if ${_OPENSSL_VERSION:M${PATTERN}} != ""
_NEED_OPENSSL=		NO
.endif
.endfor
.endif	# exists(${_OPENSSLV_H})

.if ${_NEED_OPENSSL} == "YES"
DEPENDS+=	${BUILDLINK_DEPENDS.openssl}:../../security/openssl
EVAL_PREFIX+=	BUILDLINK_PREFIX.openssl=openssl
BUILDLINK_PREFIX.openssl_DEFAULT=	${LOCALBASE}
SSLBASE=			${BUILDLINK_PREFIX.openssl}
SSLCERTS=			${SSLBASE}/certs
.else
.if ${OPSYS} == "Darwin"
BUILDLINK_PREFIX.openssl=	/usr/local
SSLBASE=			/usr/local
.else
BUILDLINK_PREFIX.openssl=	/usr
SSLBASE=			/usr
.endif
SSLCERTS=			/etc/openssl/certs
.endif
BUILD_DEFS+=			SSLBASE SSLCERTS

BUILDLINK_FILES.openssl=	bin/openssl
BUILDLINK_FILES.openssl+=	include/openssl/*
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
