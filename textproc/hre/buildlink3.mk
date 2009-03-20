# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:25:29 joerg Exp $

BUILDLINK_TREE+=	hre

.if !defined(HRE_BUILDLINK3_MK)
HRE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hre+=		hre>=0.9.7
BUILDLINK_ABI_DEPENDS.hre+=	hre>=0.9.8anb1
BUILDLINK_PKGSRCDIR.hre?=	../../textproc/hre
.endif # HRE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hre
