# $NetBSD: buildlink3.mk,v 1.2 2016/09/01 16:18:08 wiz Exp $

BUILDLINK_TREE+=	librsync

.if !defined(LIBRSYNC_BUILDLINK3_MK)
LIBRSYNC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librsync+=	librsync>=1.0.1
BUILDLINK_ABI_DEPENDS.librsync+=	librsync>=2.0
BUILDLINK_PKGSRCDIR.librsync?=	../../net/librsync
.endif	# LIBRSYNC_BUILDLINK3_MK

BUILDLINK_TREE+=	-librsync
