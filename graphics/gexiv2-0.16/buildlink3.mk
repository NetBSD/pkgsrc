# $NetBSD: buildlink3.mk,v 1.3 2026/09/12 12:47:27 wiz Exp $

BUILDLINK_TREE+=	gexiv2_0.16

.if !defined(GEXIV2_0.16_BUILDLINK3_MK)
GEXIV2_0.16_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gexiv2_0.16+=	gexiv2_0.16>=0.16.0nb1
BUILDLINK_PKGSRCDIR.gexiv2_0.16?=	../../graphics/gexiv2-0.16

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.endif	# GEXIV2_0.16_BUILDLINK3_MK

BUILDLINK_TREE+=	-gexiv2_0.16
