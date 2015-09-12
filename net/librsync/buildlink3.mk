# $NetBSD: buildlink3.mk,v 1.1 2015/09/12 22:54:01 joerg Exp $

BUILDLINK_TREE+=	librsync

.if !defined(LIBRSYNC_BUILDLINK3_MK)
LIBRSYNC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librsync+=	librsync>=1.0.1
BUILDLINK_PKGSRCDIR.librsync?=	../../net/librsync
.endif	# LIBRSYNC_BUILDLINK3_MK

BUILDLINK_TREE+=	-librsync
