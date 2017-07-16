# $NetBSD: buildlink3.mk,v 1.2 2017/07/16 21:01:06 adam Exp $
#

BUILDLINK_TREE+=	msgpack

.if !defined(MSGPACK_BUILDLINK3_MK)
MSGPACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.msgpack+=	msgpack>=1.2.0
BUILDLINK_PKGSRCDIR.msgpack?=	../../devel/msgpack
.endif	# MSGPACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-msgpack
