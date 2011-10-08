# $NetBSD: builtin.mk,v 1.1.2.2 2011/10/08 20:32:17 tron Exp $

BUILTIN_PKG:=	hesiod

.include "../../mk/bsd.fast.prefs.mk"

BUILTIN_FIND_FILES_VAR:=	H_HESIOD
BUILTIN_FIND_FILES.H_HESIOD=	/usr/include/hesiod.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.hesiod)
IS_BUILTIN.hesiod=	no
.  if empty(H_HESIOD:M__nonexistent__) && empty(H_HESIOD:M${LOCALBASE}/*)
IS_BUILTIN.hesiod=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.hesiod

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.hesiod) && \
    !empty(IS_BUILTIN.hesiod:M[yY][eE][sS]) && \
    empty(H_HESIOD:M__nonexistent__)
# 3.0.2: bug fixes. 3.0.1: added HESIOD_INTERFACES symbol
_BLTN_HESIOD_302!=	\
	${GREP} -c HESIOD_INTERFACES ${H_HESIOD} || ${TRUE}
# 3.0.0: added hesiod_* functions
_BLTN_HESIOD_300!=	\
	${GREP} -c hesiod_init ${H_HESIOD} || ${TRUE}

.  if ${_BLTN_HESIOD_302} == "1"
BUILTIN_VERSION.hesiod=		3.0.2
.  elif ${_BLTN_HESIOD_300} == "1"
BUILTIN_VERSION.hesiod=		3.0.0
.  else
BUILTIN_VERSION.hesiod=		2.0.0
.  endif
BUILTIN_PKG.hesiod=	hesiod-${BUILTIN_VERSION.hesiod}
.endif
MAKEVARS+=	BUILTIN_PKG.hesiod

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.hesiod)
.  if ${PREFER.hesiod} == "pkgsrc"
USE_BUILTIN.hesiod=	no
.  else
USE_BUILTIN.hesiod=	${IS_BUILTIN.hesiod}
.    if defined(BUILTIN_PKG.hesiod) && \
        !empty(IS_BUILTIN.hesiod:M[yY][eE][sS])
USE_BUILTIN.hesiod=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.hesiod}
.        if !empty(USE_BUILTIN.hesiod:M[yY][eE][sS])
USE_BUILTIN.hesiod!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.hesiod:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.hesiod
.endif
MAKEVARS+=	USE_BUILTIN.hesiod
