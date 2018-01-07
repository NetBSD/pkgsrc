# $NetBSD: buildlink3.mk,v 1.10 2018/01/07 13:04:31 rillig Exp $

BUILDLINK_TREE+=	fam

.if !defined(FAM_BUILDLINK3_MK)
FAM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fam+=	fam>=2.6.10
BUILDLINK_ABI_DEPENDS.fam+=	fam>=2.7.0nb7
BUILDLINK_PKGSRCDIR.fam?=	../../sysutils/fam
.endif # FAM_BUILDLINK3_MK

BUILDLINK_TREE+=	-fam
