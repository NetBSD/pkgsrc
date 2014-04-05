# $NetBSD: buildlink3.mk,v 1.1 2014/04/05 23:54:16 ryoon Exp $

BUILDLINK_TREE+=	gfortran

.if !defined(GFORTRAN_BUILDLINK3_MK)
GFORTRAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gfortran+=	gfortran>=4.8.2
BUILDLINK_PKGSRCDIR.gfortran?=	../../lang/gfortran
.endif	# GFORTRAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-gfortran
