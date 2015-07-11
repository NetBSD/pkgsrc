# $NetBSD: buildlink3.mk,v 1.1 2015/07/11 16:41:55 wiz Exp $

BUILDLINK_TREE+=	libgdata06

.if !defined(LIBGDATA06_BUILDLINK3_MK)
LIBGDATA06_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgdata06+=	libgdata>=0.6.4<0.16
BUILDLINK_ABI_DEPENDS.libgdata06+=	libgdata>=0.6.6nb16
BUILDLINK_PKGSRCDIR.libgdata06?=	../../net/libgdata0.6

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"

.endif	# LIBGDATA06_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgdata06
