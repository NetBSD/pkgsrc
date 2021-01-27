# $NetBSD: Makefile,v 1.6 2021/01/27 16:52:28 leot Exp $

DISTNAME=	json2tsv-0.6
CATEGORIES=	textproc
MASTER_SITES=	https://codemadness.org/releases/json2tsv/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://codemadness.org/git/json2tsv/file/README.html
COMMENT=	Convert JSON to TSV
LICENSE=	isc

USE_LANGUAGES=	c99

MAKE_FLAGS+=		PREFIX=${PREFIX:Q}
MAKE_FLAGS+=		MANPREFIX=${PREFIX:Q}/${PKGMANDIR:Q}
MAKE_FLAGS+=		CC=${CC:Q}

.include "../../mk/bsd.pkg.mk"
