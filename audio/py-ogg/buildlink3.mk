# $NetBSD: buildlink3.mk,v 1.3 2004/02/20 03:12:22 minskim Exp $
#
# This Makefile fragment is included by packages that use py-ogg.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PY_OGG_BUILDLINK3_MK:=	${PY_OGG_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pyogg
.endif

.if !empty(PY_OGG_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			pyogg
BUILDLINK_DEPENDS.pyogg+=		${PYPKGPREFIX}-ogg>=1.3
BUILDLINK_PKGSRCDIR.pyogg?=		../../audio/py-ogg

.include "../../audio/libogg/buildlink3.mk"

.endif # PY_OGG_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
