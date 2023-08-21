# $NetBSD: Makefile,v 1.27 2023/08/21 13:07:14 leot Exp $

DISTNAME=	sfeed-1.9
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

# Needed for cur_term
LDFLAGS.NetBSD+=	-lterminfo

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
