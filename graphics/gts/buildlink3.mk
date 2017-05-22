# $NetBSD: buildlink3.mk,v 1.2 2017/05/22 08:53:35 adam Exp $

BUILDLINK_TREE+=	gts

.if !defined(GTS_BUILDLINK3_MK)
GTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gts+=	gts>=0.7.6
BUILDLINK_PKGSRCDIR.gts?=	../../graphics/gts

.include "../../devel/glib2/buildlink3.mk"
.endif	# GTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gts
