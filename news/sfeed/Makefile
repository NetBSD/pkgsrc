# $NetBSD: Makefile,v 1.6 2019/05/05 17:46:36 leot Exp $

DISTNAME=	sfeed-0.9.10
CATEGORIES=	news
MASTER_SITES=	http://codemadness.org/releases/sfeed/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://codemadness.org/git/sfeed/file/README.html
COMMENT=	RSS and Atom parser
LICENSE=	isc

USE_LANGUAGES=	c99

MAKE_FLAGS+=		PREFIX=${PREFIX:Q}
MAKE_FLAGS+=		MANPREFIX=${PREFIX:Q}/${PKGMANDIR:Q}
MAKE_FLAGS+=		CC=${CC:Q}

REPLACE_SH+=		sfeed_opml_export sfeed_update

.include "../../mk/bsd.pkg.mk"
