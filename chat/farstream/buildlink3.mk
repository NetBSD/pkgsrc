# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:03:57 rillig Exp $

BUILDLINK_TREE+=	farstream

.if !defined(FARSTREAM_BUILDLINK3_MK)
FARSTREAM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.farstream+=	farstream>=0.2.7
BUILDLINK_PKGSRCDIR.farstream?=		../../chat/farstream

.endif	# FARSTREAM_BUILDLINK3_MK

BUILDLINK_TREE+=	-farstream
