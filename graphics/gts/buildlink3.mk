# $NetBSD: buildlink3.mk,v 1.5 2026/09/02 19:02:41 wiz Exp $

BUILDLINK_TREE+=	gts

.if !defined(GTS_BUILDLINK3_MK)
GTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gts+=	gts>=0.7.6
BUILDLINK_ABI_DEPENDS.gts?=	gts>=0.7.6nb8
BUILDLINK_PKGSRCDIR.gts?=	../../graphics/gts

.include "../../devel/glib2/buildlink3.mk"
.endif	# GTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gts
