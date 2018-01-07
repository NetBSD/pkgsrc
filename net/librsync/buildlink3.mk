# $NetBSD: buildlink3.mk,v 1.3 2018/01/07 13:04:27 rillig Exp $

BUILDLINK_TREE+=	librsync

.if !defined(LIBRSYNC_BUILDLINK3_MK)
LIBRSYNC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librsync+=	librsync>=1.0.1
BUILDLINK_ABI_DEPENDS.librsync+=	librsync>=2.0
BUILDLINK_PKGSRCDIR.librsync?=		../../net/librsync
.endif	# LIBRSYNC_BUILDLINK3_MK

BUILDLINK_TREE+=	-librsync
