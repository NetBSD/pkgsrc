# $NetBSD: buildlink3.mk,v 1.1 2004/02/21 19:17:33 minskim Exp $
#
# This Makefile fragment is included by packages that use oaf.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OAF_BUILDLINK3_MK:=	${OAF_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	oaf
.endif

.if !empty(OAF_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			oaf
BUILDLINK_DEPENDS.oaf+=		oaf>=0.6.10nb4
BUILDLINK_PKGSRCDIR.oaf?=		../../devel/oaf

.include "../../devel/popt/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

.endif # OAF_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
