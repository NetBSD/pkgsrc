# $NetBSD: builtin-common.mk,v 1.2 2021/12/02 18:22:07 nia Exp $

BUILTIN_PKG:=	${X11_BUILTIN_NAME}

BUILTIN_FIND_FILES_VAR:=		${X11_DRV_NAME:tu}
BUILTIN_FIND_FILES.${X11_DRV_NAME:tu}=	${X11BASE}/lib/modules/drivers/${X11_DRV_NAME}.so
BUILTIN_FIND_FILES.${X11_DRV_NAME:tu}+=	${X11BASE}/lib/modules/input/${X11_DRV_NAME}.so
BUILTIN_FIND_FILES.${X11_DRV_NAME:tu}+=	${X11BASE}/lib/xorg/modules/drivers/${X11_DRV_NAME}.so
BUILTIN_FIND_FILES.${X11_DRV_NAME:tu}+=	${X11BASE}/lib/xorg/modules/input/${X11_DRV_NAME}.so

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.${X11_BUILTIN_NAME})
.  if empty(${X11_DRV_NAME:tu}:M__nonexistent__)
IS_BUILTIN.${X11_BUILTIN_NAME}=	yes
.  else
IS_BUILTIN.${X11_BUILTIN_NAME}=	no
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.${X11_BUILTIN_NAME}

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.${X11_BUILTIN_NAME}) && \
    !empty(IS_BUILTIN.${X11_BUILTIN_NAME}:M[yY][eE][sS]) && \
    empty(${X11_DRV_NAME:tu}:M__nonexistent__)

# we're more worried about existence, rather than actual version
BUILTIN_VERSION.${X11_BUILTIN_NAME}=	0

BUILTIN_PKG.${X11_BUILTIN_NAME}=	${X11_BUILTIN_NAME}-${BUILTIN_VERSION.${X11_BUILTIN_NAME}}
.endif
MAKEVARS+=		BUILTIN_PKG.${X11_BUILTIN_NAME}

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.${X11_BUILTIN_NAME})
.  if ${PREFER.${X11_BUILTIN_NAME}} == "pkgsrc"
USE_BUILTIN.${X11_BUILTIN_NAME}=	no
.  else
USE_BUILTIN.${X11_BUILTIN_NAME}=	${IS_BUILTIN.${X11_BUILTIN_NAME}}
.    if defined(BUILTIN_PKG.${X11_BUILTIN_NAME}) && \
        !empty(IS_BUILTIN.${X11_BUILTIN_NAME}:M[yY][eE][sS])
USE_BUILTIN.${X11_BUILTIN_NAME}=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.${X11_BUILTIN_NAME}}
.        if !empty(USE_BUILTIN.${X11_BUILTIN_NAME}:M[yY][eE][sS])
USE_BUILTIN.${X11_BUILTIN_NAME}!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.${X11_BUILTIN_NAME}:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.${X11_BUILTIN_NAME}
.endif
