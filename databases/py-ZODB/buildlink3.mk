# $NetBSD: buildlink3.mk,v 1.1 2004/02/25 23:07:51 minskim Exp $
#
# This Makefile fragment is included by packages that use py-ZODB.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PY_ZODB_BUILDLINK3_MK:=	${PY_ZODB_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pyZODB
.endif

.if !empty(PY_ZODB_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			pyZODB
BUILDLINK_DEPENDS.pyZODB+=		${PYPKGPREFIX}-ZODB>=3.2nb1
BUILDLINK_PKGSRCDIR.pyZODB?=		../../databases/py-ZODB

.endif # PY_ZODB_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
