# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/02/24 04:57:07 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PDCURSES_BUILDLINK3_MK:=	${PDCURSES_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pdcurses
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npdcurses}
BUILDLINK_PACKAGES+=	pdcurses
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}pdcurses

.if !empty(PDCURSES_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.pdcurses+=	pdcurses>=3.3
BUILDLINK_PKGSRCDIR.pdcurses?=		../../devel/pdcurses
.endif	# PDCURSES_BUILDLINK3_MK

.include "../../mk/xaw.buildlink3.mk"

.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
