# $NetBSD: buildlink2.mk,v 1.5 2003/09/28 09:13:57 jlam Exp $
#
# This Makefile fragment is included by packages that use gnome-games.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(GNOME_GAMES_BUILDLINK2_MK)
GNOME_GAMES_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnome-games
BUILDLINK_DEPENDS.gnome-games?=		gnome-games>=1.4.0.4nb7
BUILDLINK_PKGSRCDIR.gnome-games?=		../../games/gnome-games

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnome-games=gnome-games
BUILDLINK_PREFIX.gnome-games_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gnome-games+=	include/gdkcardimage/gdk-card-image.h
BUILDLINK_FILES.gnome-games+=	lib/gnome-stones/objects/libgnome-stones.*
BUILDLINK_FILES.gnome-games+=	lib/gnome-stones/objects/libgnomekoban.*
BUILDLINK_FILES.gnome-games+=	lib/libgdkcardimage.*

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../lang/guile14/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"

BUILDLINK_TARGETS+=	gnome-games-buildlink

gnome-games-buildlink: _BUILDLINK_USE

.endif	# GNOME_GAMES_BUILDLINK2_MK
