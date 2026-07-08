# $NetBSD: buildlink3.mk,v 1.11 2026/07/08 09:08:34 wiz Exp $

BUILDLINK_TREE+=	gexiv2

.if !defined(GEXIV2_BUILDLINK3_MK)
GEXIV2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gexiv2+=	gexiv2>=0.12.0<0.16
BUILDLINK_ABI_DEPENDS.gexiv2+=	gexiv2>=0.14.3nb2
BUILDLINK_PKGSRCDIR.gexiv2?=	../../graphics/gexiv2

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.endif	# GEXIV2_BUILDLINK3_MK

BUILDLINK_TREE+=	-gexiv2
