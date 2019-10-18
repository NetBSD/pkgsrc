# $NetBSD: buildlink3.mk,v 1.1 2019/10/18 16:55:50 nia Exp $

BUILDLINK_TREE+=	libmediaart

.if !defined(LIBMEDIAART_BUILDLINK3_MK)
LIBMEDIAART_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmediaart+=	libmediaart>=1.9.4
BUILDLINK_PKGSRCDIR.libmediaart?=	../../multimedia/libmediaart

.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBMEDIAART_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmediaart
