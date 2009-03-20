# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:44 joerg Exp $

BUILDLINK_TREE+=	pfstools

.if !defined(PFSTOOLS_BUILDLINK3_MK)
PFSTOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pfstools+=	pfstools>=1.7.0
BUILDLINK_PKGSRCDIR.pfstools?=	../../graphics/pfstools
.endif # PFSTOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-pfstools
