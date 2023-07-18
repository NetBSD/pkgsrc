# $NetBSD: Makefile,v 1.4 2023/07/18 18:47:52 nia Exp $

DISTNAME=	ansifilter-2.18
CATEGORIES=	textproc
MASTER_SITES=	http://www.andre-simon.de/zip/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.andre-simon.de/doku/ansifilter/en/ansifilter.php
COMMENT=	Converts text containing terminal escape codes into markup
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++11

MAKE_FILE=	makefile
MAKE_FLAGS+=	PREFIX=${PREFIX:Q}
MAKE_FLAGS+=	man_dir=${PREFIX:Q}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
