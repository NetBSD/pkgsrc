# $NetBSD: buildlink3.mk,v 1.6 2023/08/14 05:24:36 wiz Exp $

BUILDLINK_TREE+=	pfstools

.if !defined(PFSTOOLS_BUILDLINK3_MK)
PFSTOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pfstools+=	pfstools>=1.7.0
BUILDLINK_ABI_DEPENDS.pfstools+=	pfstools>=2.2.0nb1
BUILDLINK_PKGSRCDIR.pfstools?=		../../graphics/pfstools
.endif # PFSTOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-pfstools
