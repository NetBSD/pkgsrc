# $NetBSD: buildlink3.mk,v 1.5 2004/04/01 19:04:10 jmmv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_GAMES_BUILDLINK3_MK:=	${GNOME_GAMES_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-games
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-games}
BUILDLINK_PACKAGES+=	gnome-games

.if !empty(GNOME_GAMES_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnome-games+=		gnome-games>=2.6.0
BUILDLINK_PKGSRCDIR.gnome-games?=	../../games/gnome2-games
.endif	# GNOME_GAMES_BUILDLINK3_MK

.include "../../devel/GConf2-ui/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
