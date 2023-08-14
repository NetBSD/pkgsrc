# $NetBSD: buildlink3.mk,v 1.4 2023/08/14 05:24:30 wiz Exp $

BUILDLINK_TREE+=	babl

.if !defined(BABL_BUILDLINK3_MK)
BABL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.babl+=	babl>=0.1.10
BUILDLINK_ABI_DEPENDS.babl?=	babl>=0.1.106nb1
BUILDLINK_PKGSRCDIR.babl?=	../../graphics/babl

.include "../../mk/dlopen.buildlink3.mk"
.endif # BABL_BUILDLINK3_MK

BUILDLINK_TREE+=	-babl
