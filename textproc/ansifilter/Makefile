# $NetBSD: Makefile,v 1.3 2021/07/13 08:23:41 nia Exp $

DISTNAME=	ansifilter-2.18
CATEGORIES=	textproc
MASTER_SITES=	http://www.andre-simon.de/zip/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.andre-simon.de/doku/ansifilter/en/ansifilter.php
COMMENT=	Converts text containing terminal escape codes into markup
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

GCC_REQD+=	4.7 # C++11

MAKE_FILE=	makefile
MAKE_FLAGS+=	PREFIX=${PREFIX:Q}
MAKE_FLAGS+=	man_dir=${PREFIX:Q}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
