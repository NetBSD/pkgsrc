# $NetBSD: builtin.mk,v 1.2 2004/12/05 05:35:28 jlam Exp $

.if !defined(IS_BUILTIN.libdes)
IS_BUILTIN.libdes=		no
.  if exists(/usr/include/libdes.h) || exists(/usr/include/des.h)
IS_BUILTIN.libdes=		yes
.  endif
.endif	# IS_BUILTIN.libdes

USE_BUILTIN.libdes?=	${IS_BUILTIN.libdes}

CHECK_BUILTIN.libdes?=	no
.if !empty(CHECK_BUILTIN.libdes:M[nN][oO])
.  if !empty(USE_BUILTIN.libdes:M[yY][eE][sS])
BUILDLINK_TARGETS+=	buildlink-libdes-libdes-h
.    if !target(buildlink-libdes-libdes-h)
.PHONY: buildlink-libdes-libdes-h
buildlink-libdes-libdes-h:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	dest="${BUILDLINK_DIR}/include/libdes.h";			\
	src="/usr/include/des.h";					\
	if ${TEST} ! -f "$$dest" -a -f "$$src"; then			\
		${LN} -fs $$src $$dest;					\
	fi
.    endif
.  endif # USE_BUILTIN.libdes == yes
.endif	# CHECK_BUILTIN.libdes
