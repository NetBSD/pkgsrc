# $NetBSD: buildlink3.mk,v 1.2 2004/02/15 02:04:05 minskim Exp $
#
# This Makefile fragment is included by packages that use py23pth-ogg.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PY23PTH_OGG_BUILDLINK3_MK:=	${PY23PTH_OGG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	py23pth-ogg
.endif

.if !empty(PY23PTH_OGG_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			py23pth-ogg
BUILDLINK_DEPENDS.py23pth-ogg+=		py23pth-ogg>=1.3
BUILDLINK_PKGSRCDIR.py23pth-ogg?=		../../audio/py-ogg

.include "../../audio/libogg/buildlink3.mk"

.endif # PY23PTH_OGG_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
