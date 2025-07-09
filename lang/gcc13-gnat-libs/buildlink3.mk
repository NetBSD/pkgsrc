# $NetBSD: buildlink3.mk,v 1.4 2025/07/09 17:21:59 dkazankov Exp $

BUILDLINK_TREE+=	gcc13-gnat-libs

.if !defined(GCC13_GNAT_LIBS_BUILDLINK3_MK)
GCC13_GNAT_LIBS_BUILDLINK3_MK:=

.if !empty(USE_PKGSRC_GCC_RUNTIME:M[Yy][Ee][Ss])
BUILDLINK_API_DEPENDS.gcc13-gnat-libs+=	gcc13-gnat-libs>=13.2.0
.else
BUILDLINK_API_DEPENDS.gcc13-gnat-libs+=	{gcc13-gnat,gcc13-gnat-libs}>=13.2.0
.endif
BUILDLINK_PKGSRCDIR.gcc13-gnat-libs?=	../../lang/gcc13-gnat-libs
BUILDLINK_DEPMETHOD.gcc13-gnat-libs?=	full

BUILDLINK_CONTENTS_FILTER.gcc13-gnat-libs=	${FALSE}

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.endif # GCC13_GNAT_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc13-gnat-libs
