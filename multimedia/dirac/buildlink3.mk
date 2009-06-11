# $NetBSD: buildlink3.mk,v 1.7 2009/06/11 17:28:42 joerg Exp $

BUILDLINK_TREE+=	dirac

.if !defined(DIRAC_BUILDLINK3_MK)
DIRAC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dirac+=	dirac>=1.0.2
BUILDLINK_PKGSRCDIR.dirac?=	../../multimedia/dirac
.endif # DIRAC_BUILDLINK3_MK

BUILDLINK_TREE+=	-dirac
