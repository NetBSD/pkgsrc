# $NetBSD: buildlink2.mk,v 1.7 2003/12/29 00:02:47 xtraeme Exp $
#
# This Makefile fragment is included by packages that use gnome-games.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(GNOME_GAMES_BUILDLINK2_MK)
GNOME_GAMES_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnome-games
BUILDLINK_DEPENDS.gnome-games?=		gnome-games>=2.4.1
BUILDLINK_PKGSRCDIR.gnome-games?=		../../gnome-2.4/gnome2-games

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnome-games=gnome-games
BUILDLINK_PREFIX.gnome-games_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gnome-games+=	include/gdkcardimage/gdk-card-image.h
BUILDLINK_FILES.gnome-games+=	lib/gnome-stones/objects/libgnome-stones.*
BUILDLINK_FILES.gnome-games+=	lib/gnome-stones/objects/libgnomekoban.*
BUILDLINK_FILES.gnome-games+=	lib/libgdkcardimage.*

.include "../../devel/GConf2-ui/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libgnome/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../lang/guile/buildlink2.mk"

BUILDLINK_TARGETS+=	gnome-games-buildlink

gnome-games-buildlink: _BUILDLINK_USE

.endif	# GNOME_GAMES_BUILDLINK2_MK
