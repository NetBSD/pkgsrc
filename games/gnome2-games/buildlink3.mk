# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 08:06:32 xtraeme Exp $
#
# This Makefile fragment is included by packages that use gnome-games.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GNOME_GAMES_BUILDLINK3_MK:=	${GNOME_GAMES_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-games
.endif

.if !empty(GNOME_GAMES_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gnome-games
BUILDLINK_DEPENDS.gnome-games+=		gnome-games>=2.4.1nb1
BUILDLINK_PKGSRCDIR.gnome-games?=	../../games/gnome2-games

.include "../../devel/GConf2-ui/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"

.endif # GNOME_GAMES_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
