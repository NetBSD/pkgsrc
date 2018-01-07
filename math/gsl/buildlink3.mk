# $NetBSD: buildlink3.mk,v 1.9 2018/01/07 13:04:22 rillig Exp $

BUILDLINK_TREE+=	gsl

.if !defined(GSL_BUILDLINK3_MK)
GSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gsl+=	gsl>=1.4
BUILDLINK_ABI_DEPENDS.gsl+=	gsl>=1.5nb1
BUILDLINK_PKGSRCDIR.gsl?=	../../math/gsl
.endif # GSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gsl
