# $NetBSD: buildlink3.mk,v 1.1 2021/02/20 21:58:35 ryoon Exp $

BUILDLINK_TREE+=	capnproto

.if !defined(CAPNPROTO_BUILDLINK3_MK)
CAPNPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.capnproto+=	capnproto>=0.8.0
BUILDLINK_PKGSRCDIR.capnproto?=		../../devel/capnproto

.endif	# CAPNPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-capnproto
