# $NetBSD: buildlink2.mk,v 1.3 2002/09/05 12:44:21 jlam Exp $
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
OPENSSL_VERSION_096D=		0x0090604fL
OPENSSL_VERSION_096E=		0x0090605fL
OPENSSL_VERSION_096F=		0x0090606fL
OPENSSL_VERSION_096G=		0x0090607fL

# Check for a usable installed version of OpenSSL. Version must be greater
# than 0.9.6f, or else contain a fix for the 2002-07-30 security advisory.
# If a usable version isn't present, then use the pkgsrc OpenSSL package.
#
_NEED_OPENSSL=		YES

_OPENSSLV_H=		/usr/include/openssl/opensslv.h
_SSL_H=			/usr/include/openssl/ssl.h

.if exists(${_OPENSSLV_H}) && exists(${_SSL_H})
_IN_TREE_OPENSSL_HAS_FIX!=						\
		${AWK} 'BEGIN { ans = "NO" }				\
		/SSL_R_SSL2_CONNECTION_ID_TOO_LONG/ { ans = "YES" }	\
		END { print ans; exit 0 }' ${_SSL_H}

.  if ${_IN_TREE_OPENSSL_HAS_FIX} == "YES"
USE_OPENSSL_VERSION?=	${OPENSSL_VERSION_096F}
.  else
USE_OPENSSL_VERSION?=	${OPENSSL_VERSION_096G}
.  endif

_OPENSSL_VERSION!=	${AWK} '/.*OPENSSL_VERSION_NUMBER.*/ { print $$3 }' \
				${_OPENSSLV_H}

# There never was a package for this; only the in-tree openssl had it.
#_VALID_SSL_VERSIONS=	${OPENSSL_VERSION_096F}		# OpenSSL 0.9.6f
#BUILDLINK_DEPENDS.openssl=	openssl>=0.9.6f

.  if ${USE_OPENSSL_VERSION} == ${OPENSSL_VERSION_096G}	# OpenSSL 0.9.6g
_VALID_SSL_VERSIONS=	${OPENSSL_VERSION_096G}
BUILDLINK_DEPENDS.openssl=	openssl>=0.9.6g
.  else
_VALID_SSL_VERSIONS+=	${OPENSSL_VERSION_096G}
.  endif

.  for PATTERN in ${_VALID_SSL_VERSIONS}
.    if ${_OPENSSL_VERSION:M${PATTERN}} != ""
_NEED_OPENSSL=		NO
.    endif
.  endfor
.endif	# exists(${_OPENSSLV_H}) && exists(${_SSL_H})

BUILDLINK_DEPENDS.openssl?=	openssl>=0.9.6g
BUILDLINK_PKGSRCDIR.openssl?=	../../security/openssl

.if ${_NEED_OPENSSL} == "YES"
BUILDLINK_PACKAGES+=		openssl
EVAL_PREFIX+=	BUILDLINK_PREFIX.openssl=openssl
BUILDLINK_PREFIX.openssl_DEFAULT=	${LOCALBASE}
SSLBASE=			${BUILDLINK_PREFIX.openssl}
.else
BUILDLINK_PREFIX.openssl=	/usr
SSLBASE=			/usr
.endif

.if defined(PKG_SYSCONFDIR.openssl)
SSLCERTS=			${PKG_SYSCONFDIR.openssl}/certs
.elif ${OPSYS} == "NetBSD"
SSLCERTS=			/etc/openssl/certs
.else
SSLCERTS=			${PKG_SYSCONFBASE}/openssl/certs
.endif
BUILD_DEFS+=			SSLBASE SSLCERTS

BUILDLINK_FILES.openssl=	include/openssl/*
BUILDLINK_FILES.openssl+=	lib/libRSAglue.*
BUILDLINK_FILES.openssl+=	lib/libcrypto.*
BUILDLINK_FILES.openssl+=	lib/libssl.*

.if defined(USE_RSAREF2) && ${USE_RSAREF2} == YES
.  include "../../security/rsaref/buildlink2.mk"
.endif

BUILDLINK_TARGETS+=	openssl-buildlink

openssl-buildlink: _BUILDLINK_USE

.endif	# OPENSSL_BUILDLINK2_MK
