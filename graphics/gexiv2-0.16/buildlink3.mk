# $NetBSD: buildlink3.mk,v 1.2 2026/09/02 19:02:36 wiz Exp $

BUILDLINK_TREE+=	gexiv2

.if !defined(GEXIV2_BUILDLINK3_MK)
GEXIV2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gexiv2+=	gexiv2>=0.16.0
BUILDLINK_ABI_DEPENDS.gexiv2?=	gexiv2>=0.16.0nb1
BUILDLINK_PKGSRCDIR.gexiv2?=	../../graphics/gexiv2-0.16

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.endif	# GEXIV2_BUILDLINK3_MK

BUILDLINK_TREE+=	-gexiv2
