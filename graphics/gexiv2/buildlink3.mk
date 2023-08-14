# $NetBSD: buildlink3.mk,v 1.7 2023/08/14 05:24:32 wiz Exp $

BUILDLINK_TREE+=	gexiv2

.if !defined(GEXIV2_BUILDLINK3_MK)
GEXIV2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gexiv2+=	gexiv2>=0.12.0
BUILDLINK_ABI_DEPENDS.gexiv2?=	gexiv2>=0.14.1nb3
BUILDLINK_PKGSRCDIR.gexiv2?=	../../graphics/gexiv2

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.endif	# GEXIV2_BUILDLINK3_MK

BUILDLINK_TREE+=	-gexiv2
