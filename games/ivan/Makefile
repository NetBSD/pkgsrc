# $NetBSD: Makefile,v 1.14 2008/07/27 21:44:47 dholland Exp $
#

DISTNAME=		ivan-0.50
PKGREVISION=		7
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
