# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:25:02 joerg Exp $

BUILDLINK_TREE+=	dirac

.if !defined(DIRAC_BUILDLINK3_MK)
DIRAC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dirac+=	dirac>=0.2.0
BUILDLINK_PKGSRCDIR.dirac?=	../../multimedia/dirac
BUILDLINK_DEPMETHOD.dirac?=	build
.endif # DIRAC_BUILDLINK3_MK

BUILDLINK_TREE+=	-dirac
