# $NetBSD: buildlink3.mk,v 1.1 2024/06/14 13:19:53 ktnb Exp $

BUILDLINK_TREE+=	suitesparse

.if !defined(SUITESPARSE_BUILDLINK3_MK)
SUITESPARSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.suitesparse+=	suitesparse>=3.6.1
BUILDLINK_PKGSRCDIR.suitesparse?=	../../math/suitesparse

.include "../../mk/blas.buildlink3.mk"
.include "../../math/metis/buildlink3.mk"
.endif	# SUITESPARSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-suitesparse
