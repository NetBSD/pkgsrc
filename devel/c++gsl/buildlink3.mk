# $NetBSD: buildlink3.mk,v 1.3 2023/12/13 11:44:26 nros Exp $

BUILDLINK_TREE+=	c++gsl

.if !defined(C++GSL_BUILDLINK3_MK)
C++GSL_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	c++14

BUILDLINK_API_DEPENDS.c++gsl+=	c++gsl>=4.0.0
BUILDLINK_PKGSRCDIR.c++gsl?=	../../devel/c++gsl
BUILDLINK_DEPMETHOD.c++gsl?=	build
.endif	# C++GSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-c++gsl
