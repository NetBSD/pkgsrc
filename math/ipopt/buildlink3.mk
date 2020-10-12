# $NetBSD: buildlink3.mk,v 1.2 2020/10/12 21:51:57 bacon Exp $

BUILDLINK_TREE+=	Ipopt

.if !defined(IPOPT_BUILDLINK3_MK)
IPOPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Ipopt+=	Ipopt>=3.11.5
BUILDLINK_ABI_DEPENDS.Ipopt?=	Ipopt>=3.11.5nb1
BUILDLINK_PKGSRCDIR.Ipopt?=	../../math/ipopt

.include "../../mk/blas.buildlink3.mk"
.endif	# IPOPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-Ipopt
