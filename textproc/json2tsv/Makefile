# $NetBSD: Makefile,v 1.5 2020/02/23 20:44:25 leot Exp $

DISTNAME=	json2tsv-0.5
CATEGORIES=	textproc
MASTER_SITES=	http://codemadness.org/releases/json2tsv/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://codemadness.org/git/json2tsv/file/README.html
COMMENT=	Convert JSON to TSV
LICENSE=	isc

USE_LANGUAGES=	c99

MAKE_FLAGS+=		PREFIX=${PREFIX:Q}
MAKE_FLAGS+=		MANPREFIX=${PREFIX:Q}/${PKGMANDIR:Q}
MAKE_FLAGS+=		CC=${CC:Q}

.include "../../mk/bsd.pkg.mk"
