# $NetBSD: buildlink3.mk,v 1.12 2008/10/09 19:01:57 bad Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
JPILOT_BUILDLINK3_MK:=	${JPILOT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	jpilot
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Njpilot}
BUILDLINK_PACKAGES+=	jpilot
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}jpilot

.if !empty(JPILOT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.jpilot+=	jpilot>=1.6.0
BUILDLINK_ABI_DEPENDS.jpilot+=	jpilot>=1.6.0
BUILDLINK_PKGSRCDIR.jpilot?=	../../comms/jpilot
.endif	# JPILOT_BUILDLINK3_MK

.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
