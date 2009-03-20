# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:56 joerg Exp $

BUILDLINK_TREE+=	eigen

.if !defined(EIGEN_BUILDLINK3_MK)
EIGEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.eigen+=	eigen>=2.0beta3
BUILDLINK_PKGSRCDIR.eigen?=	../../math/eigen2
BUILDLINK_DEPMETHOD.eigen?=	build
.endif # EIGEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-eigen
