# $NetBSD: buildlink3.mk,v 1.4 2025/07/09 17:27:05 dkazankov Exp $

BUILDLINK_TREE+=	gcc14-gnat-libs

.if !defined(GCC14_GNAT_LIBS_BUILDLINK3_MK)
GCC14_GNAT_LIBS_BUILDLINK3_MK:=

.if !empty(USE_PKGSRC_GCC_RUNTIME:M[Yy][Ee][Ss])
BUILDLINK_API_DEPENDS.gcc14-gnat-libs+=	gcc14-gnat-libs>=14.1.0
.else
BUILDLINK_API_DEPENDS.gcc14-gnat-libs+=	{gcc14-gnat,gcc14-gnat-libs}>=14.1.0
.endif
BUILDLINK_PKGSRCDIR.gcc14-gnat-libs?=	../../lang/gcc14-gnat-libs
BUILDLINK_DEPMETHOD.gcc14-gnat-libs?=	full

BUILDLINK_CONTENTS_FILTER.gcc14-gnat-libs=	${FALSE}

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.endif # GCC14_GNAT_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc14-gnat-libs
