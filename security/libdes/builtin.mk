# $NetBSD: builtin.mk,v 1.1 2004/07/31 05:31:57 tv Exp $

.if !defined(IS_BUILTIN.libdes)
IS_BUILTIN.libdes=		no
.  if exists(/usr/include/libdes.h)
IS_BUILTIN.libdes=		yes
.  elif exists(/usr/include/des.h)

IS_BUILTIN.libdes=		yes
BUILDLINK_TARGETS+=		buildlink-libdes-libdes-h

buildlink-libdes-libdes-h:
	${LN} -s -f /usr/include/des.h ${BUILDLINK_DIR}/include/libdes.h

.  endif
.endif	# IS_BUILTIN.libdes

USE_BUILTIN.libdes?=		${IS_BUILTIN.libdes}
