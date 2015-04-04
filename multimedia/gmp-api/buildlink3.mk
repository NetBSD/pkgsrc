# $NetBSD: buildlink3.mk,v 1.1 2015/04/04 15:45:53 tnn Exp $

BUILDLINK_TREE+=	gmp-api

.if !defined(GMP_API_BUILDLINK3_MK)
GMP_API_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gmp-api+=	gmp-api>=38.0
BUILDLINK_PKGSRCDIR.gmp-api?=	../../multimedia/gmp-api
BUILDLINK_DEPMETHOD.gmp-api?=	build
.endif	# GMP_API_BUILDLINK3_MK

BUILDLINK_TREE+=	-gmp-api
