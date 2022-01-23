# $NetBSD: buildlink3.mk,v 1.1 2022/01/23 20:34:46 nros Exp $

BUILDLINK_TREE+=	c++gsl

.if !defined(C++GSL_BUILDLINK3_MK)
C++GSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.c++gsl+=	c++gsl>=3.1.0
BUILDLINK_PKGSRCDIR.c++gsl?=	../../devel/c++gsl
BUILDLINK_DEPMETHOD.c++gsl?=	build
.endif	# C++GSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-c++gsl
