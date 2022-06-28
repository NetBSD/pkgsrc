# $NetBSD: buildlink3.mk,v 1.4 2022/06/28 11:35:01 wiz Exp $

BUILDLINK_TREE+=	librsync

.if !defined(LIBRSYNC_BUILDLINK3_MK)
LIBRSYNC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librsync+=	librsync>=1.0.1
BUILDLINK_ABI_DEPENDS.librsync+=	librsync>=2.3.2nb2
BUILDLINK_PKGSRCDIR.librsync?=		../../net/librsync
.endif	# LIBRSYNC_BUILDLINK3_MK

BUILDLINK_TREE+=	-librsync
