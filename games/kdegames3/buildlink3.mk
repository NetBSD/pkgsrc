# $NetBSD: buildlink3.mk,v 1.1 2004/04/20 13:59:34 markd Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
KDEGAMES_BUILDLINK3_MK:=	${KDEGAMES_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	kdegames
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkdegames}
BUILDLINK_PACKAGES+=	kdegames

.if !empty(KDEGAMES_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.kdegames+=	kdegames>=3.2.0
BUILDLINK_RECOMMENDED.kdegames?=	kdegames>=3.2.2
BUILDLINK_PKGSRCDIR.kdegames?=	../../games/kdegames3
.endif	# KDEGAMES_BUILDLINK3_MK

.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
