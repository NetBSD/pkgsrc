# $NetBSD: buildlink2.mk,v 1.10 2003/11/12 07:55:02 wiz Exp $

.if !defined(OPENSSL_BUILDLINK2_MK)
OPENSSL_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

# This is the ${PKGNAME} of the version of the OpenSSL package installed
# by pkgsrc.
#
_OPENSSL_PKGSRC_PKGNAME=	openssl-0.9.6l

BUILDLINK_DEPENDS.openssl?=	openssl>=0.9.6l
BUILDLINK_PKGSRCDIR.openssl?=	../../security/openssl

BUILDLINK_CHECK_BUILTIN.openssl?=	NO

_OPENSSL_OPENSSLV_H=	/usr/include/openssl/opensslv.h
_OPENSSL_SSL_H=		/usr/include/openssl/ssl.h

.if !defined(BUILDLINK_IS_BUILTIN.openssl)
BUILDLINK_IS_BUILTIN.openssl=	NO
.  if exists(${_OPENSSL_OPENSSLV_H})
BUILDLINK_IS_BUILTIN.openssl=	YES
.  endif
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.openssl:M[yY][eE][sS])
_NEED_OPENSSL=	NO
.else
.  if !empty(BUILDLINK_IS_BUILTIN.openssl:M[nN][oO])
_NEED_OPENSSL=	YES
.  elif !defined(_NEED_OPENSSL)
_OPENSSL_HAS_FIX=	NO
.    if exists(${_OPENSSL_SSL_H})
_OPENSSL_HAS_20020730_FIX!=						\
	${AWK} 'BEGIN { ans = "NO" }					\
		/SSL_R_SSL2_CONNECTION_ID_TOO_LONG/ { ans = "YES" }	\
		END { print ans; exit 0 }				\
	' ${_OPENSSL_SSL_H}
.    endif
#
# Create an appropriate name for the built-in package distributed
# with the system.  This package name can be used to check against
# BUILDLINK_DEPENDS.<pkg> to see if we need to install the pkgsrc
# version or if the built-in one is sufficient.
#
_OPENSSL_MAJOR!=							\
	${AWK} '/\#define[ 	]*OPENSSL_VERSION_NUMBER/ {		\
			print int(substr($$3, 3, 1)); exit 0;		\
		}							\
	' ${_OPENSSL_OPENSSLV_H}
_OPENSSL_MINOR!=							\
	${AWK} '/\#define[ 	]*OPENSSL_VERSION_NUMBER/ {		\
			print "." int(substr($$3, 4, 2)); exit 0;	\
		}							\
	' ${_OPENSSL_OPENSSLV_H}
_OPENSSL_TEENY!=							\
	${AWK} '/\#define[ 	]*OPENSSL_VERSION_NUMBER/ {		\
			print "." int(substr($$3, 6, 2)); exit 0;	\
		}							\
	' ${_OPENSSL_OPENSSLV_H}
_OPENSSL_PATCHLEVEL!=							\
	${AWK} 'BEGIN { split("abcdefghijklmnopqrstuvwxyz", alpha, "") } \
		/\#define[ 	]*OPENSSL_VERSION_NUMBER/ {		\
			i = int(substr($$3, 8, 2));			\
			if (i == 0) {					\
				print "";				\
			} else if (i > 26) {				\
				print "a";				\
			} else {					\
				print alpha[i];				\
			}						\
			exit 0;						\
		}							\
	' ${_OPENSSL_OPENSSLV_H}
_OPENSSL_VERSION=	${_OPENSSL_MAJOR}${_OPENSSL_MINOR}${_OPENSSL_TEENY}${_OPENSSL_PATCHLEVEL}
_OPENSSL_PKG=	openssl-${_OPENSSL_VERSION}
_OPENSSL_DEPENDS=	${BUILDLINK_DEPENDS.openssl}
_NEED_OPENSSL!=		\
	if ${PKG_ADMIN} pmatch '${_OPENSSL_DEPENDS}' ${_OPENSSL_PKG}; then \
		${ECHO} "NO";						\
	else								\
		${ECHO} "YES";						\
	fi
MAKEFLAGS+=	_NEED_OPENSSL="${_NEED_OPENSSL}"
.  endif   # !defined(_NEED_OPENSSL)
.endif

.if !defined(_NEED_NEWER_OPENSSL)
_NEED_NEWER_OPENSSL!=	\
	if ${PKG_ADMIN} pmatch '${BUILDLINK_DEPENDS.openssl}' ${_OPENSSL_PKGSRC_PKGNAME}; then \
		${ECHO} "NO";						\
	else								\
		${ECHO} "YES";						\
	fi
MAKEFLAGS+=	_NEED_NEWER_OPENSSL="${_NEED_NEWER_OPENSSL}"
.endif

.if (${_NEED_OPENSSL} == "YES") && (${_NEED_NEWER_OPENSSL} == "YES")
PKG_SKIP_REASON=	"Unable to satisfy dependency: ${BUILDLINK_DEPENDS.openssl}"
.endif

.if ${_NEED_OPENSSL} == "YES"
.  if defined(USE_RSAREF2) && !empty(USE_RSAREF2:M[yY][eE][sS])
BUILDLINK_DEPENDS+=	rsaref
.    include "../../security/rsaref/buildlink2.mk"
.  endif
.endif

.if ${_NEED_OPENSSL} == "YES"
BUILDLINK_PACKAGES+=			openssl
EVAL_PREFIX+=				BUILDLINK_PREFIX.openssl=openssl
BUILDLINK_PREFIX.openssl_DEFAULT=	${LOCALBASE}
.else
BUILDLINK_PREFIX.openssl=		/usr
.endif
SSLBASE=		${BUILDLINK_PREFIX.openssl}
BUILD_DEFS+=		SSLBASE

.if defined(PKG_SYSCONFDIR.openssl)
SSLCERTS=		${PKG_SYSCONFDIR.openssl}/certs
.elif ${OPSYS} == "NetBSD"
SSLCERTS=		/etc/openssl/certs
.else
SSLCERTS=		${PKG_SYSCONFBASE}/openssl/certs
.endif
BUILD_DEFS+=		SSLCERTS

BUILDLINK_FILES.openssl=	include/openssl/*
BUILDLINK_FILES.openssl+=	lib/libRSAglue.*
BUILDLINK_FILES.openssl+=	lib/libcrypto.*
BUILDLINK_FILES.openssl+=	lib/libssl.*

BUILDLINK_TARGETS+=	openssl-buildlink

openssl-buildlink: _BUILDLINK_USE

.endif	# OPENSSL_BUILDLINK2_MK
