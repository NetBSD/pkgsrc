# $NetBSD: buildlink3.mk,v 1.1 2004/02/14 18:43:43 minskim Exp $
#
# This Makefile fragment is included by packages that use jpilot.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
JPILOT_BUILDLINK3_MK:=	${JPILOT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	jpilot
.endif

.if !empty(JPILOT_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			jpilot
BUILDLINK_DEPENDS.jpilot+=		jpilot>=0.99.5nb4
BUILDLINK_PKGSRCDIR.jpilot?=		../../comms/jpilot

.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif # JPILOT_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
