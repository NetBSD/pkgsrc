# $NetBSD: buildlink3.mk,v 1.1 2022/10/08 13:15:07 adam Exp $

BUILDLINK_TREE+=	cppzmq

.if !defined(CPPZMQ_BUILDLINK3_MK)
CPPZMQ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cppzmq+=	cppzmq>=4.8.1
BUILDLINK_PKGSRCDIR.cppzmq?=	../../net/cppzmq
BUILDLINK_DEPMETHOD.cppzmq?=	build

.include "../../net/zeromq/buildlink3.mk"
.endif	# CPPZMQ_BUILDLINK3_MK

BUILDLINK_TREE+=	-cppzmq
