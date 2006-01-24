# $NetBSD: buildlink3.mk,v 1.5 2006/01/24 07:32:09 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
KDEGAMES_BUILDLINK3_MK:=	${KDEGAMES_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	kdegames
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkdegames}
BUILDLINK_PACKAGES+=	kdegames

.if !empty(KDEGAMES_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.kdegames+=	kdegames>=3.5.0nb1
BUILDLINK_RECOMMENDED.kdegames?=	kdegames>=3.5.0nb2
BUILDLINK_PKGSRCDIR.kdegames?=	../../games/kdegames3
.endif	# KDEGAMES_BUILDLINK3_MK

.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
