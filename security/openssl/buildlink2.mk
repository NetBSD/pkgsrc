# $NetBSD: buildlink2.mk,v 1.1.2.3 2002/06/21 23:00:39 jlam Exp $
#
# Optionally define USE_OPENSSL_VERSION to the mininum OpenSSL version
# number in <openssl/opensslv.h>, i.e. 0x0090600fL, etc.

.if !defined(OPENSSL_BUILDLINK2_MK)
OPENSSL_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

# OpenSSL version numbers from <openssl/opensslv.h>
OPENSSL_VERSION_095A=		0x0090581fL
OPENSSL_VERSION_096=		0x0090600fL
OPENSSL_VERSION_096A=		0x0090601fL
OPENSSL_VERSION_096B=		0x0090602fL

# Check for a usable installed version of OpenSSL.  Version must be greater
# than 0.9.5a.  If a usable version isn't present, then use the pkgsrc
# OpenSSL package.
#
USE_OPENSSL_VERSION?=		${OPENSSL_VERSION_095A}

# Associate OpenSSL dependency with version number.
.if ${USE_OPENSSL_VERSION} == ${OPENSSL_VERSION_095A}
BUILDLINK_DEPENDS.openssl=	{openssl-0.9.5a,openssl>=0.9.6}
.else
BUILDLINK_DEPENDS.openssl=	openssl>=0.9.6
.endif
BUILDLINK_PKGSRCDIR.openssl=	../../security/openssl

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

.  if ${USE_OPENSSL_VERSION} == ${OPENSSL_VERSION_096}	# OpenSSL 0.9.6
_VALID_SSL_VERSIONS=	${OPENSSL_VERSION_096}
.  else
_VALID_SSL_VERSIONS+=	${OPENSSL_VERSION_096}
.  endif

.  if ${USE_OPENSSL_VERSION} == ${OPENSSL_VERSION_096A}	# OpenSSL 0.9.6a
_VALID_SSL_VERSIONS=	${OPENSSL_VERSION_096A}
.  else
_VALID_SSL_VERSIONS+=	${OPENSSL_VERSION_096A}
.  endif

.  if ${USE_OPENSSL_VERSION} == ${OPENSSL_VERSION_096B}	# OpenSSL 0.9.6b
_VALID_SSL_VERSIONS=	${OPENSSL_VERSION_096B}
.  else
_VALID_SSL_VERSIONS+=	${OPENSSL_VERSION_096B}
.  endif

.  for PATTERN in ${_VALID_SSL_VERSIONS}
.    if ${_OPENSSL_VERSION:M${PATTERN}} != ""
_NEED_OPENSSL=		NO
.    endif
.  endfor
.endif	# exists(${_OPENSSLV_H})

.if ${_NEED_OPENSSL} == "YES"
BUILDLINK_PACKAGES+=		openssl
EVAL_PREFIX+=	BUILDLINK_PREFIX.openssl=openssl
BUILDLINK_PREFIX.openssl_DEFAULT=	${LOCALBASE}
SSLBASE=			${BUILDLINK_PREFIX.openssl}
SSLCERTS=			${SSLBASE}/certs
.else
.  if ${OPSYS} == "Darwin"
BUILDLINK_PREFIX.openssl=	/usr/local
SSLBASE=			/usr/local
.  else
BUILDLINK_PREFIX.openssl=	/usr
SSLBASE=			/usr
.  endif
SSLCERTS=			/etc/openssl/certs
.endif
BUILD_DEFS+=			SSLBASE SSLCERTS

BUILDLINK_FILES.openssl+=	include/openssl/*
BUILDLINK_FILES.openssl+=	lib/libRSAglue.*
BUILDLINK_FILES.openssl+=	lib/libcrypto.*
BUILDLINK_FILES.openssl+=	lib/libssl.*

.if defined(USE_RSAREF2) && ${USE_RSAREF2} == YES
.  include "../../security/rsaref/buildlink2.mk"
.endif

BUILDLINK_TARGETS+=		openssl-buildlink

openssl-buildlink: _BUILDLINK_USE

.endif	# OPENSSL_BUILDLINK2_MK
