# $NetBSD: buildlink3.mk,v 1.1 2004/02/14 18:31:23 minskim Exp $
#
# This Makefile fragment is included by packages that use pilot-link-libs.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PILOT_LINK_LIBS_BUILDLINK3_MK:=	${PILOT_LINK_LIBS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pilot-link-libs
.endif

.if !empty(PILOT_LINK_LIBS_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			pilot-link-libs
BUILDLINK_DEPENDS.pilot-link-libs+=		pilot-link-libs>=0.11.7nb1
BUILDLINK_PKGSRCDIR.pilot-link-libs?=		../../comms/pilot-link-libs

.include "../../devel/ncurses/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"

.endif # PILOT_LINK_LIBS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
