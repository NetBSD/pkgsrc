# $NetBSD: Makefile,v 1.1 2020/07/17 16:20:17 leot Exp $

DISTNAME=	sfeed_curses-0.8
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

.include "../../mk/bsd.pkg.mk"
