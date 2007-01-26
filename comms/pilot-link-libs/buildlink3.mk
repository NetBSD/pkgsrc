# $NetBSD: buildlink3.mk,v 1.9 2007/01/26 01:26:46 markd Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PILOT_LINK_LIBS_BUILDLINK3_MK:=	${PILOT_LINK_LIBS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pilot-link-libs
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npilot-link-libs}
BUILDLINK_PACKAGES+=	pilot-link-libs
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}pilot-link-libs

.if !empty(PILOT_LINK_LIBS_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.pilot-link-libs+=	pilot-link-libs>=0.11.7nb1
BUILDLINK_ABI_DEPENDS.pilot-link-libs+=	pilot-link-libs>=0.12.1
BUILDLINK_PKGSRCDIR.pilot-link-libs?=	../../comms/pilot-link-libs
.endif	# PILOT_LINK_LIBS_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
