# $NetBSD: buildlink3.mk,v 1.1 2004/02/26 15:26:29 adam Exp $
#
# This Makefile fragment is included by packages that use lapack.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LAPACK_BUILDLINK3_MK:=	${LAPACK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	lapack
.endif

.if !empty(LAPACK_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			lapack
BUILDLINK_DEPENDS.lapack+=		lapack>=20010201nb1
BUILDLINK_PKGSRCDIR.lapack?=		../../math/lapack

.endif # LAPACK_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
