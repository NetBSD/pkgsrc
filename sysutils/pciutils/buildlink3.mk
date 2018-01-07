# $NetBSD: buildlink3.mk,v 1.9 2018/01/07 13:04:32 rillig Exp $

BUILDLINK_TREE+=	pciutils

.if !defined(PCIUTILS_BUILDLINK3_MK)
PCIUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pciutils+=	pciutils>=3.0.2
BUILDLINK_PKGSRCDIR.pciutils?=		../../sysutils/pciutils
BUILDLINK_DEPMETHOD.pciutils?=		build
.endif # PCIUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-pciutils
