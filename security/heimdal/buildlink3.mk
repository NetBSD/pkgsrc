# $NetBSD: buildlink3.mk,v 1.2 2004/01/10 19:44:16 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
HEIMDAL_BUILDLINK3_MK:=	${HEIMDAL_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(HEIMDAL_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		heimdal
BUILDLINK_DEPENDS.heimdal?=	heimdal>=0.4e
BUILDLINK_PKGSRCDIR.heimdal?=	../../security/heimdal
BUILDLINK_INCDIRS.heimdal?=	include/krb5
.endif	# HEIMDAL_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.heimdal?=	NO

_KRB5_KRB5_H=	/usr/include/krb5/krb5.h

.if !defined(BUILDLINK_IS_BUILTIN.heimdal)
BUILDLINK_IS_BUILTIN.heimdal=	NO
.  if exists(${_KRB5_KRB5_H})
BUILDLINK_IS_BUILTIN.heimdal!=						\
	if ${GREP} -q heimdal_version ${_KRB5_KRB5_H}; then		\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
.  endif
MAKEFLAGS+=	BUILDLINK_IS_BUILTIN.heimdal="${BUILDLINK_IS_BUILTIN.heimdal}"
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.heimdal:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.heimdal=	YES
.endif

.if !defined(BUILDLINK_USE_BUILTIN.heimdal)
.  if !empty(BUILDLINK_IS_BUILTIN.heimdal:M[nN][oO])
BUILDLINK_USE_BUILTIN.heimdal=	NO
.  else
#
# Create an appropriate name for the built-in package distributed
# with the system.  This package name can be used to check against
# BUILDLINK_DEPENDS.<pkg> to see if we need to install the pkgsrc
# version or if the built-in one is sufficient.
#
# heimdal<=0.6 doesn't have a method of checking the headers to discover
# the version number of the software.  Match up heimdal versions with
# OS versions for an approximate determination of the heimdal version.
#
.if !defined(_HEIMDAL_VERSION)
_HEIMDAL_VERSIONS=	0.6 0.5 0.4e 0.3f 0.3e
_HEIMDAL_0.6=		NetBSD-1.6[U-Z]-* NetBSD-1.6Z*-*
_HEIMDAL_0.5=		NetBSD-1.6[I-T]-*
_HEIMDAL_0.4e=		NetBSD-1.6[A-H]-*				\
			NetBSD-1.6-* NetBSD-1.6_*-* NetBSD-1.6.*-*	\
			NetBSD-1.5[YZ]-* NetBSD-1.5Z*-*
_HEIMDAL_0.3f=		NetBSD-1.5X-*
_HEIMDAL_0.3e=		NetBSD-1.5[UVW]-*				\
			NetBSD-1.5.*-*
.  for _heimdal_version_ in ${_HEIMDAL_VERSIONS}
.    for _pattern_ in ${_HEIMDAL_${_heimdal_version_}}
.      if !empty(MACHINE_PLATFORM:M${_pattern_})
_HEIMDAL_VERSION?=	${_heimdal_version_}
.      endif
.    endfor
.  endfor
_HEIMDAL_VERSION?=	0.2t
MAKEFLAGS+=	_HEIMDAL_VERSION="${_HEIMDAL_VERSION}"
.endif

_HEIMDAL_PKG=		heimdal-${_HEIMDAL_VERSION}
_HEIMDAL_DEPENDS=	${BUILDLINK_DEPENDS.heimdal}
BUILDLINK_USE_BUILTIN.heimdal!=		\
	if ${PKG_ADMIN} pmatch '${_HEIMDAL_DEPENDS}' ${_HEIMDAL_PKG}; then \
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
.  endif
MAKEFLAGS+=	\
	BUILDLINK_USE_BUILTIN.heimdal="${BUILDLINK_USE_BUILTIN.heimdal}"
.endif

.if !empty(BUILDLINK_USE_BUILTIN.heimdal:M[nN][oO])
#
# If we depend on the package, depend on the latest version with a library
# major number bump.
#
BUILDLINK_DEPENDS.heimdal=	heimdal>=0.6
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=		heimdal
.  endif
.endif

.if !empty(HEIMDAL_BUILDLINK3_MK:M+)
.  if !empty(BUILDLINK_USE_BUILTIN.heimdal:M[yY][eE][sS])
BUILDLINK_FILES.heimdal=	include/krb5/*.h
.  else
KRB5_CONFIG?=	${BUILDLINK_PREFIX.heimdal}/bin/krb5-config
CONFIGURE_ENV+=	KRB5_CONFIG="${KRB5_CONFIG}"
MAKE_ENV+=	KRB5_CONFIG="${KRB5_CONFIG}"
.  endif
.endif	# HEIMDAL_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
