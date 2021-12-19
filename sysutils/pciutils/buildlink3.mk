# $NetBSD: buildlink3.mk,v 1.10 2021/12/19 09:47:59 maya Exp $

BUILDLINK_TREE+=	pciutils

.if !defined(PCIUTILS_BUILDLINK3_MK)
PCIUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pciutils+=	pciutils>=3.0.2
BUILDLINK_PKGSRCDIR.pciutils?=		../../sysutils/pciutils
.endif # PCIUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-pciutils
