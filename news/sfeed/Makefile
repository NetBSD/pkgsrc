# $NetBSD: Makefile,v 1.22 2022/02/10 11:35:16 leot Exp $

DISTNAME=	sfeed-1.2
CATEGORIES=	news
MASTER_SITES=	https://codemadness.org/releases/sfeed/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://codemadness.org/git/sfeed/file/README.html
COMMENT=	RSS and Atom parser
LICENSE=	isc

USE_LANGUAGES=	c99

MAKE_FLAGS+=		PREFIX=${PREFIX:Q}
MAKE_FLAGS+=		MANPREFIX=${PREFIX:Q}/${PKGMANDIR:Q}
MAKE_FLAGS+=		CC=${CC:Q}

REPLACE_SH+=		sfeed_markread sfeed_opml_export sfeed_update

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
