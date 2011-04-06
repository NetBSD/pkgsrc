# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/04/06 13:01:30 obache Exp $
#

BUILDLINK_TREE+=	msgpack

.if !defined(MSGPACK_BUILDLINK3_MK)
MSGPACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.msgpack+=	msgpack>=0.5.5
BUILDLINK_PKGSRCDIR.msgpack?=	../../devel/msgpack
.endif	# MSGPACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-msgpack
