# $NetBSD: buildlink3.mk,v 1.2 2004/03/05 19:25:09 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PILOT_LINK_LIBS_BUILDLINK3_MK:=	${PILOT_LINK_LIBS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pilot-link-libs
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npilot-link-libs}
BUILDLINK_PACKAGES+=	pilot-link-libs

.if !empty(PILOT_LINK_LIBS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.pilot-link-libs+=	pilot-link-libs>=0.11.7nb1
BUILDLINK_PKGSRCDIR.pilot-link-libs?=	../../comms/pilot-link-libs

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"

.endif	# PILOT_LINK_LIBS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
