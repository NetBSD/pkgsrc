# $NetBSD: buildlink3.mk,v 1.3 2017/02/12 21:50:17 adam Exp $

BUILDLINK_TREE+=	pfstools

.if !defined(PFSTOOLS_BUILDLINK3_MK)
PFSTOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pfstools+=	pfstools>=1.7.0
BUILDLINK_PKGSRCDIR.pfstools?=		../../graphics/pfstools
.endif # PFSTOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-pfstools
