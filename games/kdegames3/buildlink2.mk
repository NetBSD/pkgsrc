# $NetBSD: buildlink2.mk,v 1.2 2003/12/08 14:41:39 wiz Exp $
#
# This Makefile fragment is included by packages that use kdegames.
#
# This file was created automatically using createbuildlink 2.7.
#

.if !defined(KDEGAMES_BUILDLINK2_MK)
KDEGAMES_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			kdegames
BUILDLINK_DEPENDS.kdegames?=		kdegames>=3.1.4nb1
BUILDLINK_PKGSRCDIR.kdegames?=		../../games/kdegames3

EVAL_PREFIX+=	BUILDLINK_PREFIX.kdegames=kdegames
BUILDLINK_PREFIX.kdegames_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.kdegames+=	include/atlantic/atlantic_core.h
BUILDLINK_FILES.kdegames+=	include/atlantic/auction.h
BUILDLINK_FILES.kdegames+=	include/atlantic/estate.h
BUILDLINK_FILES.kdegames+=	include/atlantic/estategroup.h
BUILDLINK_FILES.kdegames+=	include/atlantic/player.h
BUILDLINK_FILES.kdegames+=	include/atlantic/trade.h
BUILDLINK_FILES.kdegames+=	include/atlantik/ui/auction_widget.h
BUILDLINK_FILES.kdegames+=	include/atlantik/ui/board.h
BUILDLINK_FILES.kdegames+=	include/atlantik/ui/display_widget.h
BUILDLINK_FILES.kdegames+=	include/atlantik/ui/estatedetails.h
BUILDLINK_FILES.kdegames+=	include/atlantik/ui/estateview.h
BUILDLINK_FILES.kdegames+=	include/atlantik/ui/portfolioestate.h
BUILDLINK_FILES.kdegames+=	include/atlantik/ui/portfolioview.h
BUILDLINK_FILES.kdegames+=	include/atlantik/ui/token.h
BUILDLINK_FILES.kdegames+=	include/atlantik/ui/trade_widget.h
BUILDLINK_FILES.kdegames+=	include/kcanvasrootpixmap.h
BUILDLINK_FILES.kdegames+=	include/kcarddialog.h
BUILDLINK_FILES.kdegames+=	include/kchat.h
BUILDLINK_FILES.kdegames+=	include/kchatbase.h
BUILDLINK_FILES.kdegames+=	include/kchatdialog.h
BUILDLINK_FILES.kdegames+=	include/kgame/kgame.h
BUILDLINK_FILES.kdegames+=	include/kgame/kgamechat.h
BUILDLINK_FILES.kdegames+=	include/kgame/kgameconnectdialog.h
BUILDLINK_FILES.kdegames+=	include/kgame/kgamedebugdialog.h
BUILDLINK_FILES.kdegames+=	include/kgame/kgamedialog.h
BUILDLINK_FILES.kdegames+=	include/kgame/kgamedialogconfig.h
BUILDLINK_FILES.kdegames+=	include/kgame/kgameerror.h
BUILDLINK_FILES.kdegames+=	include/kgame/kgameerrordialog.h
BUILDLINK_FILES.kdegames+=	include/kgame/kgameio.h
BUILDLINK_FILES.kdegames+=	include/kgame/kgamemessage.h
BUILDLINK_FILES.kdegames+=	include/kgame/kgamenetwork.h
BUILDLINK_FILES.kdegames+=	include/kgame/kgameprocess.h
BUILDLINK_FILES.kdegames+=	include/kgame/kgameproperty.h
BUILDLINK_FILES.kdegames+=	include/kgame/kgamepropertyarray.h
BUILDLINK_FILES.kdegames+=	include/kgame/kgamepropertyhandler.h
BUILDLINK_FILES.kdegames+=	include/kgame/kgamepropertylist.h
BUILDLINK_FILES.kdegames+=	include/kgame/kmessageclient.h
BUILDLINK_FILES.kdegames+=	include/kgame/kmessageio.h
BUILDLINK_FILES.kdegames+=	include/kgame/kmessageserver.h
BUILDLINK_FILES.kdegames+=	include/kgame/kplayer.h
BUILDLINK_FILES.kdegames+=	include/kgamemisc.h
BUILDLINK_FILES.kdegames+=	include/kgameprogress.h
BUILDLINK_FILES.kdegames+=	include/khighscore.h
BUILDLINK_FILES.kdegames+=	include/kolf/ball.h
BUILDLINK_FILES.kdegames+=	include/kolf/canvasitem.h
BUILDLINK_FILES.kdegames+=	include/kolf/config.h
BUILDLINK_FILES.kdegames+=	include/kolf/floater.h
BUILDLINK_FILES.kdegames+=	include/kolf/game.h
BUILDLINK_FILES.kdegames+=	include/kolf/object.h
BUILDLINK_FILES.kdegames+=	include/kolf/rtti.h
BUILDLINK_FILES.kdegames+=	include/kolf/slope.h
BUILDLINK_FILES.kdegames+=	include/kolf/statedb.h
BUILDLINK_FILES.kdegames+=	include/kolf/vector.h
BUILDLINK_FILES.kdegames+=	include/kscoredialog.h
BUILDLINK_FILES.kdegames+=	include/kstdgameaction.h
BUILDLINK_FILES.kdegames+=	lib/kde3/kio_atlantik.*
BUILDLINK_FILES.kdegames+=	lib/kde3/kolf.*
BUILDLINK_FILES.kdegames+=	lib/libatlantic.*
BUILDLINK_FILES.kdegames+=	lib/libatlantikclient.*
BUILDLINK_FILES.kdegames+=	lib/libatlantikui.*
BUILDLINK_FILES.kdegames+=	lib/libkdegames.*
BUILDLINK_FILES.kdegames+=	lib/libkolf.*

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"

BUILDLINK_TARGETS+=	kdegames-buildlink

kdegames-buildlink: _BUILDLINK_USE

.endif	# KDEGAMES_BUILDLINK2_MK
