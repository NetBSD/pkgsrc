# $NetBSD: buildlink3.mk,v 1.2 2021/06/29 08:25:35 nia Exp $

BUILDLINK_TREE+=	capnproto

.if !defined(CAPNPROTO_BUILDLINK3_MK)
CAPNPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.capnproto+=	capnproto>=0.8.0
BUILDLINK_PKGSRCDIR.capnproto?=		../../devel/capnproto

BUILDLINK_FILES.capnproto+=	bin/capnp
BUILDLINK_FILES.capnproto+=	bin/capnpc
BUILDLINK_FILES.capnproto+=	bin/capnpc-c++
BUILDLINK_FILES.capnproto+=	bin/capnpc-capnp

.endif	# CAPNPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-capnproto
