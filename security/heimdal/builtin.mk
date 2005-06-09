# $NetBSD: builtin.mk,v 1.5 2005/06/09 06:07:29 jlam Exp $

BUILTIN_PKG:=	heimdal

BUILTIN_FIND_FILES_VAR:=	H_HEIMDAL
BUILTIN_FIND_FILES.H_HEIMDAL=	/usr/include/krb5/krb5.h
BUILTIN_FIND_GREP.H_HEIMDAL=	heimdal_version

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.heimdal)
IS_BUILTIN.heimdal=	no
.  if empty(H_HEIMDAL:M${LOCALBASE}/*) && exists(${H_HEIMDAL})
IS_BUILTIN.heimdal=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.heimdal

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.heimdal) && \
    !empty(IS_BUILTIN.heimdal:M[yY][eE][sS])
#
# heimdal<=0.6 doesn't have a method of checking the headers to discover
# the version number of the software.  Match up heimdal versions with
# OS versions for an approximate determination of the heimdal version.
#
_BLTN_HEIMDAL_VERSIONS=	0.6  0.5  0.4e  0.3f  0.3e
_BLTN_HEIMDAL_0.6.3=	NetBSD-[2-9]*-*
_BLTN_HEIMDAL_0.6.2=	# empty
_BLTN_HEIMDAL_0.6.1=	NetBSD-1.6[U-Z]-* NetBSD-1.6Z*-*
_BLTN_HEIMDAL_0.6=	NetBSD-1.6[U-Z]-* NetBSD-1.6Z*-* NetBSD-[2-9]*-*
_BLTN_HEIMDAL_0.5=	NetBSD-1.6[I-T]-*
_BLTN_HEIMDAL_0.4e=	NetBSD-1.6[A-H]-*				\
			NetBSD-1.6-* NetBSD-1.6_*-* NetBSD-1.6.*-*	\
			NetBSD-1.5[YZ]-* NetBSD-1.5Z*-*
_BLTN_HEIMDAL_0.3f=	NetBSD-1.5X-*
_BLTN_HEIMDAL_0.3e=	NetBSD-1.5[UVW]-*				\
			NetBSD-1.5.*-*
.  for _heimdal_version_ in ${_BLTN_HEIMDAL_VERSIONS}
.    for _pattern_ in ${_BLTN_HEIMDAL_${_heimdal_version_}}
.      if !empty(MACHINE_PLATFORM:M${_pattern_})
BUILTIN_VERSION.heimdal?=	${_heimdal_version_}
.      endif
.    endfor
.  endfor
BUILTIN_VERSION.heimdal?=	0.2t
BUILTIN_PKG.heimdal=		heimdal-${BUILTIN_VERSION.heimdal}
.endif
MAKEVARS+=	BUILTIN_PKG.heimdal

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.heimdal)
.  if ${PREFER.heimdal} == "pkgsrc"
USE_BUILTIN.heimdal=	no
.  else
USE_BUILTIN.heimdal=	${IS_BUILTIN.heimdal}
.    if defined(BUILTIN_PKG.heimdal) && \
        !empty(IS_BUILTIN.heimdal:M[yY][eE][sS])
USE_BUILTIN.heimdal=	yes
.      for _dep_ in ${BUILDLINK_DEPENDS.heimdal}
.        if !empty(USE_BUILTIN.heimdal:M[yY][eE][sS])
USE_BUILTIN.heimdal!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.heimdal:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.heimdal
.endif
MAKEVARS+=	USE_BUILTIN.heimdal

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.heimdal?=	no
.if !empty(CHECK_BUILTIN.heimdal:M[nN][oO])

.  if !empty(USE_BUILTIN.heimdal:M[nN][oO])
BUILDLINK_DEPENDS.heimdal+=	heimdal>=0.6

KRB5_CONFIG?=	${BUILDLINK_PREFIX.heimdal}/bin/krb5-config
CONFIGURE_ENV+=	KRB5_CONFIG=${KRB5_CONFIG:Q}
MAKE_ENV+=	KRB5_CONFIG=${KRB5_CONFIG:Q}
.  endif

.endif	# CHECK_BUILTIN.heimdal
