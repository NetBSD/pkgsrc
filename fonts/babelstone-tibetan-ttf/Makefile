# $NetBSD: Makefile,v 1.1 2021/01/02 00:05:03 uwe Exp $

VERSION=	10.5
PKGNAME=	babelstone-tibetan-ttf-${VERSION}
CATEGORIES=	fonts
DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	BabelStoneTibetan.ttf BabelStoneTibetanSlim.ttf
WRKSRC=		${WRKDIR}
MASTER_SITES=	https://www.babelstone.co.uk/Fonts/Download/

MAINTAINER=	uwe@NetBSD.org
HOMEPAGE=	https://www.babelstone.co.uk/Fonts/Tibetan.html
COMMENT=	TrueType font for Tibetan script
LICENSE=	ofl-v1.1

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
