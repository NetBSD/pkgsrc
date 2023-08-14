# $NetBSD: buildlink3.mk,v 1.1 2023/08/14 07:38:37 nros Exp $

BUILDLINK_TREE+=	czmq

.if !defined(CZMQ_BUILDLINK3_MK)
CZMQ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.czmq+=	czmq>=4.2.1
BUILDLINK_PKGSRCDIR.czmq?=	../../net/czmq

.include "../../net/zeromq/buildlink3.mk"
.endif	# CZMQ_BUILDLINK3_MK

BUILDLINK_TREE+=	-czmq
