# $NetBSD: buildlink2.mk,v 1.24 2004/04/07 13:31:54 tron Exp $

.if !defined(OPENSSL_BUILDLINK2_MK)
OPENSSL_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

# This is the ${PKGNAME} of the version of the OpenSSL package installed
# by pkgsrc.
#
_OPENSSL_PKGSRC_PKGNAME=	openssl-0.9.6m

BUILDLINK_DEPENDS.openssl?=	openssl>=0.9.6m
BUILDLINK_PKGSRCDIR.openssl?=	../../security/openssl

BUILDLINK_CHECK_BUILTIN.openssl?=	NO

_OPENSSL_OPENSSLV_H=	/usr/include/openssl/opensslv.h

.if !defined(BUILDLINK_IS_BUILTIN.openssl)
BUILDLINK_IS_BUILTIN.openssl=	NO
.  if exists(${_OPENSSL_OPENSSLV_H})
#
# Create an appropriate name for the built-in package distributed
# with the system.  This package name can be used to check against
# BUILDLINK_DEPENDS.<pkg> to see if we need to install the pkgsrc
# version or if the built-in one is sufficient.
#
_OPENSSL_MAJOR!=							\
	${AWK} 'BEGIN { hex="0123456789abcdef" }			\
		/\#define[ 	]*OPENSSL_VERSION_NUMBER/ {		\
			i = index(hex, substr($$3, 3, 1)) - 1;		\
			print i;					\
			exit 0;						\
		}							\
	' ${_OPENSSL_OPENSSLV_H}
_OPENSSL_MINOR!=							\
	${AWK} 'BEGIN { hex="0123456789abcdef" }			\
		/\#define[ 	]*OPENSSL_VERSION_NUMBER/ {		\
			i = 16 * (index(hex, substr($$3, 4, 1)) - 1);	\
			i += index(hex, substr($$3, 5, 1)) - 1;		\
			print i;					\
			exit 0;						\
		}							\
	' ${_OPENSSL_OPENSSLV_H}
_OPENSSL_TEENY!=							\
	${AWK} 'BEGIN { hex="0123456789abcdef" }			\
		/\#define[ 	]*OPENSSL_VERSION_NUMBER/ {		\
			i = 16 * (index(hex, substr($$3, 6, 1)) - 1);	\
			i += index(hex, substr($$3, 7, 1)) - 1;		\
			print i;					\
			exit 0;						\
		}							\
	' ${_OPENSSL_OPENSSLV_H}
_OPENSSL_PATCHLEVEL!=							\
	${AWK} 'BEGIN { hex="0123456789abcdef";				\
			split("abcdefghijklmnopqrstuvwxyz", alpha, "");	\
		}							\
		/\#define[ 	]*OPENSSL_VERSION_NUMBER/ {		\
			i = 16 * (index(hex, substr($$3, 8, 1)) - 1);	\
			i += index(hex, substr($$3, 9, 1)) - 1;		\
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
_OPENSSL_VERSION=	${_OPENSSL_MAJOR}.${_OPENSSL_MINOR}.${_OPENSSL_TEENY}${_OPENSSL_PATCHLEVEL}
_OPENSSL_PKG=	openssl-${_OPENSSL_VERSION}
#
# If the built-in OpenSSL software is 0.9.6g, then check whether it
# contains the security fixes pulled up to netbsd-1-6 on 2004-04-01.
# If it does, then treat it as the equivalent of openssl-0.9.6m.  This
# is not strictly true, but is good enough since the main differences
# between 0.9.6g and 0.9.6m are security fixes that NetBSD has already
# patched into its built-in OpenSSL software.
#
_OPENSSL_HAS_FIX!=							\
	${AWK} 'BEGIN { ans = "NO" }					\
		/OPENSSL_HAS_20040401_FIX/ { ans = "YES" }		\
		END { print ans; exit 0 }				\
	' ${_OPENSSL_OPENSSLV_H}
.    if !empty(_OPENSSL_VERSION:M0\.9\.6g) && (${_OPENSSL_HAS_FIX} == "YES")
_OPENSSL_PKG=		openssl-0.9.6m
.    endif

_OPENSSL_DEPENDS=	${BUILDLINK_DEPENDS.openssl}
BUILDLINK_IS_BUILTIN.openssl!=	\
	if ${PKG_ADMIN} pmatch '${_OPENSSL_DEPENDS}' ${_OPENSSL_PKG}; then \
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
.  endif
MAKEFLAGS+=	BUILDLINK_IS_BUILTIN.openssl=${BUILDLINK_IS_BUILTIN.openssl}
.endif

.if !empty(BUILDLINK_IS_BUILTIN.openssl:M[yY][eE][sS])
_NEED_OPENSSL=	NO
.else
_NEED_OPENSSL=	YES
.endif

.if !empty(PREFER_NATIVE:M[yY][eE][sS]) && \
    ${BUILDLINK_IS_BUILTIN.openssl} == "YES"
_NEED_OPENSSL=	NO
.endif
.if !empty(PREFER_PKGSRC:M[yY][eE][sS])
_NEED_OPENSSL=	YES
.endif
.if !empty(PREFER_NATIVE:Mopenssl) && \
    ${BUILDLINK_IS_BUILTIN.openssl} == "YES"
_NEED_OPENSSL=	NO
.endif
.if !empty(PREFER_PKGSRC:Mopenssl)
_NEED_OPENSSL=	YES
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.openssl:M[yY][eE][sS])
_NEED_OPENSSL=	NO
.endif

.if !defined(_NEED_NEWER_OPENSSL)
_NEED_NEWER_OPENSSL!=	\
	if ${PKG_ADMIN} pmatch '${BUILDLINK_DEPENDS.openssl}' ${_OPENSSL_PKGSRC_PKGNAME}; then \
		${ECHO} "NO";						\
	else								\
		${ECHO} "YES";						\
	fi
MAKEFLAGS+=	_NEED_NEWER_OPENSSL=${_NEED_NEWER_OPENSSL}
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
.elif ${_NEED_OPENSSL} == "NO"
SSLCERTS=		/etc/ssl/certs
.else
SSLCERTS=		${PKG_SYSCONFBASEDIR}/openssl/certs
.endif
BUILD_DEFS+=		SSLCERTS

BUILDLINK_FILES.openssl=	include/openssl/*
BUILDLINK_FILES.openssl+=	lib/libRSAglue.*
BUILDLINK_FILES.openssl+=	lib/libcrypto.*
BUILDLINK_FILES.openssl+=	lib/libssl.*

BUILDLINK_TARGETS+=	openssl-buildlink

openssl-buildlink: _BUILDLINK_USE

.endif	# OPENSSL_BUILDLINK2_MK
