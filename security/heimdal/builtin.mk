# $NetBSD: builtin.mk,v 1.2 2004/03/29 05:43:35 jlam Exp $

_KRB5_KRB5_H=	/usr/include/krb5/krb5.h

.if !defined(IS_BUILTIN.heimdal)
IS_BUILTIN.heimdal=	no
.  if exists(${_KRB5_KRB5_H})
IS_BUILTIN.heimdal!=							\
	if ${GREP} -q heimdal_version ${_KRB5_KRB5_H}; then		\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.    if !empty(IS_BUILTIN.heimdal:M[yY][eE][sS])
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
.      if !defined(_HEIMDAL_VERSION)
_HEIMDAL_VERSIONS=	0.6  0.5  0.4e  0.3f  0.3e
_HEIMDAL_0.6=		NetBSD-1.6[U-Z]-* NetBSD-1.6Z*-* NetBSD-[2-9]*-*
_HEIMDAL_0.5=		NetBSD-1.6[I-T]-*
_HEIMDAL_0.4e=		NetBSD-1.6[A-H]-*				\
			NetBSD-1.6-* NetBSD-1.6_*-* NetBSD-1.6.*-*	\
			NetBSD-1.5[YZ]-* NetBSD-1.5Z*-*
_HEIMDAL_0.3f=		NetBSD-1.5X-*
_HEIMDAL_0.3e=		NetBSD-1.5[UVW]-*				\
			NetBSD-1.5.*-*
.        for _heimdal_version_ in ${_HEIMDAL_VERSIONS}
.          for _pattern_ in ${_HEIMDAL_${_heimdal_version_}}
.            if !empty(MACHINE_PLATFORM:M${_pattern_})
_HEIMDAL_VERSION?=	${_heimdal_version_}
.            endif
.          endfor
.        endfor
_HEIMDAL_VERSION?=	0.2t
.      endif
BUILTIN_PKG.heimdal=	heimdal-${_HEIMDAL_VERSION}
MAKEFLAGS+=		BUILTIN_PKG.heimdal=${BUILTIN_PKG.heimdal}
.    endif
.  endif
MAKEFLAGS+=	IS_BUILTIN.heimdal=${IS_BUILTIN.heimdal}
.endif

.if !defined(USE_BUILTIN.heimdal)
USE_BUILTIN.heimdal?=	${IS_BUILTIN.heimdal}

.  if defined(BUILTIN_PKG.heimdal)
USE_BUILTIN.heimdal=	yes
.    for _depend_ in ${BUILDLINK_DEPENDS.heimdal}
.      if !empty(USE_BUILTIN.heimdal:M[yY][eE][sS])
USE_BUILTIN.heimdal!=	\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.heimdal}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.      endif
.    endfor
.  endif
.endif	# USE_BUILTIN.heimdal

CHECK_BUILTIN.heimdal?=	no
.if !empty(CHECK_BUILTIN.heimdal:M[nN][oO])

.if !empty(USE_BUILTIN.heimdal:M[nN][oO])
BUILDLINK_DEPENDS.heimdal+=	heimdal>=0.6

KRB5_CONFIG?=	${BUILDLINK_PREFIX.heimdal}/bin/krb5-config
CONFIGURE_ENV+=	KRB5_CONFIG="${KRB5_CONFIG}"
MAKE_ENV+=	KRB5_CONFIG="${KRB5_CONFIG}"
.endif

.endif	# CHECK_BUILTIN.heimdal
