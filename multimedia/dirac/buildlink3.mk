# $NetBSD: buildlink3.mk,v 1.8 2022/06/28 11:34:53 wiz Exp $

BUILDLINK_TREE+=	dirac

.if !defined(DIRAC_BUILDLINK3_MK)
DIRAC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dirac+=	dirac>=1.0.2
BUILDLINK_ABI_DEPENDS.dirac?=	dirac>=1.0.2nb11
BUILDLINK_PKGSRCDIR.dirac?=	../../multimedia/dirac
.endif # DIRAC_BUILDLINK3_MK

BUILDLINK_TREE+=	-dirac
