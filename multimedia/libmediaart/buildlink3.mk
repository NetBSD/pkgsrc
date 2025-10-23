# $NetBSD: buildlink3.mk,v 1.4 2025/10/23 20:38:37 wiz Exp $

BUILDLINK_TREE+=	libmediaart

.if !defined(LIBMEDIAART_BUILDLINK3_MK)
LIBMEDIAART_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmediaart+=	libmediaart>=1.9.4
BUILDLINK_ABI_DEPENDS.libmediaart?=	libmediaart>=1.9.4nb7
BUILDLINK_PKGSRCDIR.libmediaart?=	../../multimedia/libmediaart
BUILDLINK_INCDIRS.libmediaart+=		include/libmediaart-2.0

.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBMEDIAART_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmediaart
