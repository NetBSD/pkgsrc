# $NetBSD: pkgconfig-builtin.mk,v 1.1.2.4 2008/09/27 20:23:28 cube Exp $

# This file is used to factor out a common pattern in builtin.mk files backed
# up by the existence of a pkgconfig file.
#
# Caller has to define BUILTIN_PKG and PKGCONFIG_FILE.<BUILTIN_PKG>.
#
# Optionally, caller may define PKGCONFIG_BASE.<BUILTIN_PKG> as the base
# location for a native implementation of the package.  It conveniently
# defaults to X11BASE.

BUILTIN_FIND_FILES_VAR:=			FIND_FILES_${BUILTIN_PKG}
BUILTIN_FIND_FILES.FIND_FILES_${BUILTIN_PKG}=	${PKGCONFIG_FILE.${BUILTIN_PKG}}

.include "../../mk/buildlink3/bsd.builtin.mk"

PKGCONFIG_BASE.${BUILTIN_PKG}?=	${X11BASE}

.if ${PKGCONFIG_BASE.${BUILTIN_PKG}} == ${LOCALBASE}
IS_BUILTIN.${BUILTIN_PKG}=	no
.elif !defined(IS_BUILTIN.${BUILTIN_PKG})
IS_BUILTIN.${BUILTIN_PKG}=	no
.  if empty(FIND_FILES_${BUILTIN_PKG}:M__nonexistent__)
IS_BUILTIN.${BUILTIN_PKG}=	yes
.  endif
.endif
MAKEVARS:=	${MAKEVARS} IS_BUILTIN.${BUILTIN_PKG}

.if !defined(BUILTIN_PKG.${BUILTIN_PKG}) && \
    !empty(IS_BUILTIN.${BUILTIN_PKG}:M[yY][eE][sS]) && \
    !empty(FIND_FILES_${BUILTIN_PKG}:M*.pc)
BUILTIN_VERSION.${BUILTIN_PKG}!= \
	${SED} -n -e 's/Version: //p' ${FIND_FILES_${BUILTIN_PKG}}
BUILTIN_PKG.${BUILTIN_PKG}:= ${BUILTIN_PKG}-${BUILTIN_VERSION.${BUILTIN_PKG}}
.endif
MAKEVARS:=      ${MAKEVARS} BUILTIN_PKG.${BUILTIN_PKG}

.if !defined(USE_BUILTIN.${BUILTIN_PKG})
.  if ${PREFER.${BUILTIN_PKG}} == "pkgsrc"
USE_BUILTIN.${BUILTIN_PKG}=	no
.  else
USE_BUILTIN.${BUILTIN_PKG}:=	${IS_BUILTIN.${BUILTIN_PKG}}
.    if defined(BUILTIN_PKG.${BUILTIN_PKG}) && \
	!empty(IS_BUILTIN.${BUILTIN_PKG}:M[Yy][Ee][Ss])
USE_BUILTIN.${BUILTIN_PKG}=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.${BUILTIN_PKG}}
.        if !empty(USE_BUILTIN.${BUILTIN_PKG}:M[Yy][Ee][Ss])
USE_BUILTIN.${BUILTIN_PKG}!= \
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.${BUILTIN_PKG}}; then \
		${ECHO} yes; \
	else \
		${ECHO} no; \
	fi
.        endif
.      endfor
.    endif
.  endif
.endif
MAKEVARS:=	${MAKEVARS} USE_BUILTIN.${BUILTIN_PKG}
