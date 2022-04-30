# $NetBSD: buildlink3.mk,v 1.2 2022/04/30 14:33:39 mef Exp $
#

BUILDLINK_TREE+=	r_cpp11

.if !defined(R_CPP11_BUILDLINK3_MK)
R_CPP11_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.r_cpp11+=	R-cpp11>=0.4.2
BUILDLINK_ABI_DEPENDS.r_cpp11+=	R-cpp11>=0.4.2
BUILDLINK_PKGSRCDIR.r_cpp11?=	../../lang/R-cpp11

BUILDLINK_FILES.r_cpp11=	lib/R/library/cpp11/include/cpp11/*

.endif # R_CPP11_BUILDLINK3_MK

BUILDLINK_TREE+=	-r_cpp11
