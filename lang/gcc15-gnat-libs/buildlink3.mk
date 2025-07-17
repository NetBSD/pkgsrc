# $NetBSD: buildlink3.mk,v 1.1 2025/07/17 05:00:18 dkazankov Exp $

BUILDLINK_TREE+=	gcc15-gnat-libs

.if !defined(GCC15_GNAT_LIBS_BUILDLINK3_MK)
GCC15_GNAT_LIBS_BUILDLINK3_MK:=

.if !empty(USE_PKGSRC_GCC_RUNTIME:M[Yy][Ee][Ss])
BUILDLINK_API_DEPENDS.gcc15-gnat-libs+=	gcc15-gnat-libs>=15.1.0
.else
BUILDLINK_API_DEPENDS.gcc15-gnat-libs+=	{gcc15-gnat,gcc15-gnat-libs}>=15.1.0
.endif
BUILDLINK_PKGSRCDIR.gcc15-gnat-libs?=	../../lang/gcc15-gnat-libs
BUILDLINK_DEPMETHOD.gcc15-gnat-libs?=	full

BUILDLINK_CONTENTS_FILTER.gcc15-gnat-libs=	${FALSE}

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.endif # GCC15_GNAT_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc15-gnat-libs
