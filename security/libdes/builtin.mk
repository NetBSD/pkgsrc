# $NetBSD: builtin.mk,v 1.7 2013/11/23 12:10:13 obache Exp $

BUILTIN_PKG:=	libdes

BUILTIN_FIND_HEADERS_VAR:=	H_LIBDES
BUILTIN_FIND_HEADERS.H_LIBDES=	libdes.h des.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.libdes)
IS_BUILTIN.libdes=	no
.  if empty(H_LIBDES:M__nonexistent__) && empty(H_LIBDES:M${LOCALBASE}/*)
IS_BUILTIN.libdes=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.libdes

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libdes)
.  if ${PREFER.libdes} == "pkgsrc"
USE_BUILTIN.libdes=	no
.  else
USE_BUILTIN.libdes=	${IS_BUILTIN.libdes}
.    if defined(BUILTIN_PKG.libdes) && \
        !empty(IS_BUILTIN.libdes:M[yY][eE][sS])
USE_BUILTIN.libdes=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.libdes}
.        if !empty(USE_BUILTIN.libdes:M[yY][eE][sS])
USE_BUILTIN.libdes!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libdes:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libdes
.endif
MAKEVARS+=	USE_BUILTIN.libdes

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.libdes?=	no
.if !empty(CHECK_BUILTIN.libdes:M[nN][oO])

.  if !empty(USE_BUILTIN.libdes:M[yY][eE][sS])
BUILDLINK_TARGETS+=	buildlink-libdes-libdes-h
.  endif

.  if !target(buildlink-libdes-libdes-h)
.PHONY: buildlink-libdes-libdes-h
buildlink-libdes-libdes-h:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	src="/usr/include/des.h";					\
	dest=${BUILDLINK_DIR:Q}"/include/libdes.h";			\
	if ${TEST} ! -f "$$dest" -a -f "$$src"; then			\
		${MKDIR} -p `${DIRNAME} "$$dest"`;			\
		${LN} -fs "$$src" "$$dest";				\
	fi
.  endif

.endif	# CHECK_BUILTIN.libdes
