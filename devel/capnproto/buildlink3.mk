# $NetBSD: buildlink3.mk,v 1.3 2023/07/19 14:49:45 nia Exp $

BUILDLINK_TREE+=	capnproto

.if !defined(CAPNPROTO_BUILDLINK3_MK)
CAPNPROTO_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	c++14

BUILDLINK_API_DEPENDS.capnproto+=	capnproto>=0.8.0
BUILDLINK_PKGSRCDIR.capnproto?=		../../devel/capnproto

BUILDLINK_FILES.capnproto+=	bin/capnp
BUILDLINK_FILES.capnproto+=	bin/capnpc
BUILDLINK_FILES.capnproto+=	bin/capnpc-c++
BUILDLINK_FILES.capnproto+=	bin/capnpc-capnp

.endif	# CAPNPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-capnproto
