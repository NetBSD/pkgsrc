# $NetBSD: buildlink3.mk,v 1.1 2004/04/18 05:33:14 snj Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
CLANLIB_BUILDLINK3_MK:=	${CLANLIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ClanLib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NClanLib}
BUILDLINK_PACKAGES+=	ClanLib

.if !empty(CLANLIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.ClanLib+=	ClanLib>=0.4.4nb4
BUILDLINK_PKGSRCDIR.ClanLib?=	../../graphics/clanlib
.endif	# CLANLIB_BUILDLINK3_MK

.include "../../mk/pthread.buildlink3.mk"
.include "../../graphics/hermes/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
