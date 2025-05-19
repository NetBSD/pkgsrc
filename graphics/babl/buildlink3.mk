# $NetBSD: buildlink3.mk,v 1.6 2025/05/19 10:45:52 wiz Exp $

BUILDLINK_TREE+=	babl

.if !defined(BABL_BUILDLINK3_MK)
BABL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.babl+=	babl>=0.1.10
BUILDLINK_ABI_DEPENDS.babl+=	babl>=0.1.106nb1
BUILDLINK_PKGSRCDIR.babl?=	../../graphics/babl

.include "../../graphics/lcms2/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.endif # BABL_BUILDLINK3_MK

BUILDLINK_TREE+=	-babl
