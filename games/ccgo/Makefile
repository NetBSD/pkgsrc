# $NetBSD: Makefile,v 1.16 2005/04/11 21:45:48 tv Exp $
#

DISTNAME=		ccgo-0.3.4
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		http://ccdw.org/~cjj/prog/ccgo/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://ccdw.org/~cjj/prog/ccgo/
COMMENT=		Go board with IGS and gnugo interface

DEPENDS+=		gnugo>=3.4:../../games/gnugo

BUILD_USES_MSGFMT=	YES

USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

SUBST_CLASSES+=		ccgo
SUBST_STAGE.ccgo=	pre-configure
SUBST_FILES.ccgo=	game_setup.cc settings.cc
SUBST_MESSAGE.ccgo=	"Fixing paths to gnugo."
SUBST_SED.ccgo=		-e 's|/usr/games/gnugo|${PREFIX.gnugo}/bin/gnugo|g'

EVAL_PREFIX+=		PREFIX.gnugo
PREFIX.gnugo_DEFAULT=	${LOCALBASE}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gconfmm/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
