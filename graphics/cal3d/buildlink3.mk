# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/02/10 09:14:34 garbled Exp $
#
# This Makefile fragment is included by packages that use cal3d.
#
# This file was created automatically using createbuildlink-3.0.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
CAL3D_BUILDLINK3_MK:=	${CAL3D_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	cal3d
.endif

.if !empty(CAL3D_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			cal3d
BUILDLINK_DEPENDS.cal3d?=		cal3d>=0.9.1
BUILDLINK_PKGSRCDIR.cal3d?=		../../graphics/cal3d

.include "../../graphics/Mesa/buildlink3.mk"

.endif # CAL3D_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
