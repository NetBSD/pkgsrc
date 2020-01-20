# $NetBSD: buildlink3.mk,v 1.2 2020/01/20 01:26:16 nia Exp $

BUILDLINK_TREE+=	libmediaart

.if !defined(LIBMEDIAART_BUILDLINK3_MK)
LIBMEDIAART_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmediaart+=	libmediaart>=1.9.4
BUILDLINK_PKGSRCDIR.libmediaart?=	../../multimedia/libmediaart
BUILDLINK_INCDIRS.libmediaart+=		include/libmediaart-2.0

.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBMEDIAART_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmediaart
