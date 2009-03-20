# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:57 joerg Exp $

BUILDLINK_TREE+=	gsl

.if !defined(GSL_BUILDLINK3_MK)
GSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gsl+=		gsl>=1.4
BUILDLINK_ABI_DEPENDS.gsl+=	gsl>=1.5nb1
BUILDLINK_PKGSRCDIR.gsl?=	../../math/gsl
.endif # GSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gsl
