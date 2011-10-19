# $NetBSD: buildlink3.mk,v 1.3 2011/10/19 06:50:03 obache Exp $

BUILDLINK_TREE+=	libgexiv2

.if !defined(LIBGEXIV2_BUILDLINK3_MK)
LIBGEXIV2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgexiv2+=	libgexiv2>=0.2.0
BUILDLINK_ABI_DEPENDS.libgexiv2?=	libgexiv2>=0.3.1nb2
BUILDLINK_PKGSRCDIR.libgexiv2?=	../../graphics/libgexiv2

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.endif	# LIBGEXIV2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgexiv2
