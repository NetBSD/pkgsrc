# $NetBSD: buildlink3.mk,v 1.2 2023/07/20 21:45:26 nia Exp $

BUILDLINK_TREE+=	c++gsl

.if !defined(C++GSL_BUILDLINK3_MK)
C++GSL_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	c++14

BUILDLINK_API_DEPENDS.c++gsl+=	c++gsl>=3.1.0
BUILDLINK_PKGSRCDIR.c++gsl?=	../../devel/c++gsl
BUILDLINK_DEPMETHOD.c++gsl?=	build
.endif	# C++GSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-c++gsl
