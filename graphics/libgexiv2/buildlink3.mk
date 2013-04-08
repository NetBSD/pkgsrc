# $NetBSD: buildlink3.mk,v 1.9 2013/04/08 16:48:22 drochner Exp $

BUILDLINK_TREE+=	libgexiv2

.if !defined(LIBGEXIV2_BUILDLINK3_MK)
LIBGEXIV2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgexiv2+=	libgexiv2>=0.2.0
BUILDLINK_ABI_DEPENDS.libgexiv2+=	libgexiv2>=0.6.1
BUILDLINK_PKGSRCDIR.libgexiv2?=	../../graphics/libgexiv2

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.endif	# LIBGEXIV2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgexiv2
