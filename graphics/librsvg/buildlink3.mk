# $NetBSD: buildlink3.mk,v 1.16 2009/08/26 19:56:56 sno Exp $

BUILDLINK_TREE+=	librsvg

.if !defined(LIBRSVG_BUILDLINK3_MK)
LIBRSVG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librsvg+=		librsvg>=2.12.6nb1
BUILDLINK_ABI_DEPENDS.librsvg+=		librsvg>=2.26.0
BUILDLINK_PKGSRCDIR.librsvg?=		../../graphics/librsvg

.include "../../devel/libgsf/buildlink3.mk"
.include "../../textproc/libcroco/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # LIBRSVG_BUILDLINK3_MK

BUILDLINK_TREE+=	-librsvg
