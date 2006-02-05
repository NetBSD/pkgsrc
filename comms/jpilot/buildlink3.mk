# $NetBSD: buildlink3.mk,v 1.6 2006/02/05 23:08:27 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
JPILOT_BUILDLINK3_MK:=	${JPILOT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	jpilot
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Njpilot}
BUILDLINK_PACKAGES+=	jpilot

.if !empty(JPILOT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.jpilot+=	jpilot>=0.99.5nb4
BUILDLINK_RECOMMENDED.jpilot+=	jpilot>=0.99.7nb2
BUILDLINK_PKGSRCDIR.jpilot?=	../../comms/jpilot
.endif	# JPILOT_BUILDLINK3_MK

.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
