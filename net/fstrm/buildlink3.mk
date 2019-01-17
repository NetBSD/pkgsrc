# $NetBSD: buildlink3.mk,v 1.1 2019/01/17 08:10:53 he Exp $

BUILDLINK_TREE+=	fstrm

.if !defined(FSTRM_BUILDLINK3_MK)
FSTRM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fstrm+=	fstrm>=0.4.0
BUILDLINK_ABI_DEPENDS.fstrm?=	fstrm>=0.4.0
BUILDLINK_PKGSRCDIR.fstrm?=	../../net/fstrm

.endif	# FSTRM_BUILDLINK3_MK

BUILDLINK_TREE+=	-fstrm
