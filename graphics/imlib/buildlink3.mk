# $NetBSD: buildlink3.mk,v 1.36 2025/08/30 22:45:24 wiz Exp $

BUILDLINK_TREE+=	imlib

.if !defined(IMLIB_BUILDLINK3_MK)
IMLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.imlib+=	imlib>=1.9.14nb5
BUILDLINK_ABI_DEPENDS.imlib+=	imlib>=1.9.15nb26
BUILDLINK_PKGSRCDIR.imlib?=	../../graphics/imlib

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.endif # IMLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-imlib
