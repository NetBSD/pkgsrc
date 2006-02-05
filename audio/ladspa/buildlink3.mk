# $NetBSD: buildlink3.mk,v 1.3 2006/02/05 23:08:10 joerg Exp $
#
# This Makefile fragment is included by packages that use ladspa.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LADSPA_BUILDLINK3_MK:=	${LADSPA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ladspa
.endif

.if !empty(LADSPA_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			ladspa
BUILDLINK_DEPENDS.ladspa+=		ladspa>=1.12
BUILDLINK_RECOMMENDED.ladspa?=		ladspa>=1.12nb1
BUILDLINK_PKGSRCDIR.ladspa?=		../../audio/ladspa

.endif # LADSPA_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
