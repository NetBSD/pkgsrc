# $NetBSD: buildlink3.mk,v 1.1.1.1 2013/11/14 15:04:12 asau Exp $

BUILDLINK_TREE+=	Ipopt

.if !defined(IPOPT_BUILDLINK3_MK)
IPOPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Ipopt+=	Ipopt>=3.11.5
BUILDLINK_PKGSRCDIR.Ipopt?=	../../math/ipopt

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.endif	# IPOPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-Ipopt
