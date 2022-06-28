# $NetBSD: buildlink3.mk,v 1.9 2022/06/28 11:33:42 wiz Exp $

BUILDLINK_TREE+=	rpc2

.if !defined(RPC2_BUILDLINK3_MK)
RPC2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rpc2+=	rpc2>=1.10
BUILDLINK_ABI_DEPENDS.rpc2+=	rpc2>=2.10nb11
BUILDLINK_PKGSRCDIR.rpc2?=	../../devel/rpc2

.include "../../devel/lwp/buildlink3.mk"
.endif # RPC2_BUILDLINK3_MK

BUILDLINK_TREE+=	-rpc2
