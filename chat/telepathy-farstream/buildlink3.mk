# $NetBSD: buildlink3.mk,v 1.1 2015/12/01 13:03:05 jaapb Exp $

BUILDLINK_TREE+=	telepathy-farstream

.if !defined(TELEPATHY_FARSTREAM_BUILDLINK3_MK)
TELEPATHY_FARSTREAM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.telepathy-farstream+=	telepathy-farstream>=0.6.2
BUILDLINK_PKGSRCDIR.telepathy-farstream?=	../../chat/telepathy-farstream

.include "../../chat/farstream/buildlink3.mk"
.endif	# TELEPATHY_FARSTREAM_BUILDLINK3_MK

BUILDLINK_TREE+=	-telepathy-farstream
