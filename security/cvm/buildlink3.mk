# $NetBSD: buildlink3.mk,v 1.11 2018/01/07 13:04:28 rillig Exp $

BUILDLINK_TREE+=	cvm

.if !defined(CVM_BUILDLINK3_MK)
CVM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cvm+=	cvm>=0.90
BUILDLINK_PKGSRCDIR.cvm?=	../../security/cvm
.endif # CVM_BUILDLINK3_MK

BUILDLINK_TREE+=	-cvm
