# $NetBSD: buildlink3.mk,v 1.15 2009/03/20 19:24:40 joerg Exp $

BUILDLINK_TREE+=	imlib

.if !defined(IMLIB_BUILDLINK3_MK)
IMLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.imlib+=	imlib>=1.9.14nb5
BUILDLINK_ABI_DEPENDS.imlib+=	imlib>=1.9.15nb4
BUILDLINK_PKGSRCDIR.imlib?=	../../graphics/imlib

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/netpbm/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.endif # IMLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-imlib
