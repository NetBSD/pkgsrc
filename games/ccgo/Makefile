# $NetBSD: Makefile,v 1.85 2024/05/29 16:32:32 adam Exp $

DISTNAME=	ccgo-0.3.6.5
PKGREVISION=	25
CATEGORIES=	games
MASTER_SITES=	https://ccdw.org/~cjj/prog/ccgo/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ccdw.org/~cjj/prog/ccgo/
COMMENT=	Go board with IGS and gnugo interface
LICENSE=	gnu-gpl-v3

DEPENDS+=	gnugo>=3.4:../../games/gnugo

USE_LANGUAGES=		c c++11
USE_TOOLS+=		msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

SUBST_CLASSES+=		ccgo
SUBST_STAGE.ccgo=	pre-configure
SUBST_FILES.ccgo=	game_setup.cc
SUBST_MESSAGE.ccgo=	Fixing paths to gnugo.
SUBST_SED.ccgo=		-e 's|/usr/games/gnugo|${LOCALBASE}/bin/gnugo|g'

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gconfmm/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
