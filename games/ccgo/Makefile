# $NetBSD: Makefile,v 1.11 2004/02/29 12:42:22 jmmv Exp $
#

DISTNAME=		ccgo-0.3.4
CATEGORIES=		games
MASTER_SITES=		http://ccdw.org/~cjj/prog/ccgo/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://ccdw.org/~cjj/prog/ccgo/
COMMENT=		Go board with IGS and gnugo interface

DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs
DEPENDS+=		gnugo>=3.4:../../games/gnugo

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

SUBST_CLASSES+=		ccgo
SUBST_STAGE.ccgo=	pre-configure
SUBST_FILES.ccgo=	game_setup.cc settings.cc
SUBST_MESSAGE.ccgo=	"Fixing paths to gnugo."
SUBST_SED.ccgo=		-e 's|/usr/games/gnugo|${PREFIX.gnugo}/bin/gnugo|g'

EVAL_PREFIX+=		PREFIX.gnugo
PREFIX.gnugo_DEFAULT=	${LOCALBASE}

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gconfmm/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../x11/gtkmm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
