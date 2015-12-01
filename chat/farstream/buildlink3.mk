# $NetBSD: buildlink3.mk,v 1.1 2015/12/01 12:59:52 jaapb Exp $

BUILDLINK_TREE+=	farstream

.if !defined(FARSTREAM_BUILDLINK3_MK)
FARSTREAM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.farstream+=	farstream>=0.2.7
BUILDLINK_PKGSRCDIR.farstream?=	../../chat/farstream

.endif	# FARSTREAM_BUILDLINK3_MK

BUILDLINK_TREE+=	-farstream
