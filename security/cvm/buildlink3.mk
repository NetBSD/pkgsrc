# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:25:17 joerg Exp $

BUILDLINK_TREE+=	cvm

.if !defined(CVM_BUILDLINK3_MK)
CVM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cvm+=		cvm>=0.90
BUILDLINK_PKGSRCDIR.cvm?=	../../security/cvm
BUILDLINK_DEPMETHOD.cvm?=	build
.endif # CVM_BUILDLINK3_MK

BUILDLINK_TREE+=	-cvm
