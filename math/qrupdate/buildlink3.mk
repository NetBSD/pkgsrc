# $NetBSD: buildlink3.mk,v 1.1 2021/05/29 09:55:14 thor Exp $

BUILDLINK_TREE+=	qrupdate

.if !defined(QRUPDATE_BUILDLINK3_MK)
QRUPDATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qrupdate+=	qrupdate>=1.1.2
BUILDLINK_PKGSRCDIR.qrupdate?=		../../math/qrupdate

.include "../../mk/blas.buildlink3.mk"

.endif	# QRUPDATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qrupdate
