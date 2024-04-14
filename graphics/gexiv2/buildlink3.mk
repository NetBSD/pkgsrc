# $NetBSD: buildlink3.mk,v 1.8 2024/04/14 17:42:09 adam Exp $

BUILDLINK_TREE+=	gexiv2

.if !defined(GEXIV2_BUILDLINK3_MK)
GEXIV2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gexiv2+=	gexiv2>=0.12.0
BUILDLINK_ABI_DEPENDS.gexiv2+=	gexiv2>=0.14.1nb3
BUILDLINK_PKGSRCDIR.gexiv2?=	../../graphics/gexiv2

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.endif	# GEXIV2_BUILDLINK3_MK

BUILDLINK_TREE+=	-gexiv2
