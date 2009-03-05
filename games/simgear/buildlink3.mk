# $NetBSD: buildlink3.mk,v 1.3 2009/03/05 21:17:42 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SIMGEAR_BUILDLINK3_MK:=	${SIMGEAR_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	simgear
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsimgear}
BUILDLINK_PACKAGES+=	simgear
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}simgear

.if ${SIMGEAR_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.simgear+=	simgear>=1.0.0
BUILDLINK_PKGSRCDIR.simgear?=	../../games/simgear
BUILDLINK_DEPMETHOD.simgear?=	build
.endif	# SIMGEAR_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../games/plib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
