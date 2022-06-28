# $NetBSD: buildlink3.mk,v 1.4 2022/06/28 11:34:07 wiz Exp $

BUILDLINK_TREE+=	pfstools

.if !defined(PFSTOOLS_BUILDLINK3_MK)
PFSTOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pfstools+=	pfstools>=1.7.0
BUILDLINK_ABI_DEPENDS.pfstools?=		pfstools>=2.1.0nb24
BUILDLINK_PKGSRCDIR.pfstools?=		../../graphics/pfstools
.endif # PFSTOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-pfstools
