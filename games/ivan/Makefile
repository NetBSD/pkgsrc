# $NetBSD: Makefile,v 1.10 2006/06/12 16:28:09 wiz Exp $
#

DISTNAME=		ivan-0.50
PKGREVISION=		5
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ivan/}

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://ivan.sourceforge.net/
COMMENT=		Graphical roguelike featuring deep gameplay

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--localstatedir=${PREFIX}/share

USE_LANGUAGES=		c++

DEINSTALL_SRC=		${PKGDIR}/DEINSTALL
INSTALL_SRC=		# empty

CONF_FILES_PERMS+=	/dev/null ${PREFIX}/share/ivan/ivan-highscore.scores \
			${ROOT_USER} games 664

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
