# $NetBSD: buildlink3.mk,v 1.1 2016/06/18 08:16:27 kamil Exp $

BUILDLINK_TREE+=	nanomsg

.if !defined(NANOMSG_BUILDLINK3_MK)
NANOMSG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nanomsg+=	nanomsg>=1.0.0
BUILDLINK_PKGSRCDIR.nanomsg?=	../../net/nanomsg
.endif	# NANOMSG_BUILDLINK3_MK

BUILDLINK_TREE+=	-nanomsg
