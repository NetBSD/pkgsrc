# $NetBSD: Makefile,v 1.29 2012/09/15 10:04:42 obache Exp $
#

DISTNAME=		pytraffic-2.5.4
PKGREVISION=		18
CATEGORIES=		games
MASTER_SITES=	http://alpha.uhasselt.be/Research/Algebra/Members/pytraffic/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=	http://alpha.uhasselt.be/Research/Algebra/Members/pytraffic/
COMMENT=		Computer version of a popular board game

PKG_DESTDIR_SUPPORT=	user-destdir

# pytraffic-2.5.4 distfile was changed after release
DIST_SUBDIR=	pytraffic-2.5.4-070313

PYDISTUTILSPKG=		yes

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
