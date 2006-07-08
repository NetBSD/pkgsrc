# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:10:59 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
OCTAVE_FORGE_BUILDLINK3_MK:=	${OCTAVE_FORGE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	octave-forge
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Noctave-forge}
BUILDLINK_PACKAGES+=	octave-forge
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}octave-forge

.if !empty(OCTAVE_FORGE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.octave-forge+=	octave-forge>=2005.06.13
BUILDLINK_ABI_DEPENDS.octave-forge?=	octave-forge>=2005.06.13nb1
BUILDLINK_PKGSRCDIR.octave-forge?=	../../math/octave-forge
.endif	# OCTAVE_FORGE_BUILDLINK3_MK

.include "../../math/octave/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
