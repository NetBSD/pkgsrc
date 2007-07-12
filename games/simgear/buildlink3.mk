# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/07/12 19:56:14 drochner Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SIMGEAR_BUILDLINK3_MK:=	${SIMGEAR_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	simgear
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsimgear}
BUILDLINK_PACKAGES+=	simgear

.if !empty(SIMGEAR_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.simgear+=	simgear>=0.3.4
BUILDLINK_PKGSRCDIR.simgear?=	../../games/simgear
BUILDLINK_DEPMETHOD.simgear?=	build
.endif	# SIMGEAR_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../games/plib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
