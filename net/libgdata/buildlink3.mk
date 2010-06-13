# $NetBSD: buildlink3.mk,v 1.2 2010/06/13 22:45:11 wiz Exp $

BUILDLINK_TREE+=	libgdata

.if !defined(LIBGDATA_BUILDLINK3_MK)
LIBGDATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgdata+=	libgdata>=0.1.1
BUILDLINK_ABI_DEPENDS.libgdata?=	libgdata>=0.5.2nb1
BUILDLINK_PKGSRCDIR.libgdata?=	../../net/libgdata


.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"

.endif	# LIBGDATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgdata
