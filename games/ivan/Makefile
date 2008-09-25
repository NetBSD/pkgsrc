# $NetBSD: Makefile,v 1.15 2008/09/25 14:02:09 wiz Exp $
#

DISTNAME=		ivan-0.50
PKGREVISION=		8
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ivan/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ivan.sourceforge.net/
COMMENT=		Graphical roguelike featuring deep gameplay

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--localstatedir=${PREFIX}/share

USE_LANGUAGES=		c c++

REQD_DIRS+=		share/ivan
CONF_FILES_PERMS+=	/dev/null ${PREFIX}/share/ivan/ivan-highscore.scores \
			${ROOT_USER} games 664

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
