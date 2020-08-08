# $NetBSD: Makefile,v 1.3 2020/08/08 15:41:31 leot Exp $

DISTNAME=	sfeed_curses-0.9
CATEGORIES=	news
MASTER_SITES=	http://codemadness.org/releases/sfeed_curses/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://codemadness.org/git/sfeed_curses/file/README.html
COMMENT=	Sfeed curses UI
LICENSE=	isc

USE_LANGUAGES=	c99

MAKE_FLAGS+=		PREFIX=${PREFIX:Q}
MAKE_FLAGS+=		MANPREFIX=${PREFIX:Q}/${PKGMANDIR:Q}
MAKE_FLAGS+=		CC=${CC:Q}

REPLACE_SH+=		sfeed_markread

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
