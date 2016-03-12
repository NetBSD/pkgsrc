# $NetBSD: Makefile,v 1.1 2016/03/12 11:49:19 tnn Exp $

DISTNAME=	ansifilter-1.15
CATEGORIES=	textproc
MASTER_SITES=	http://www.andre-simon.de/zip/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.andre-simon.de/doku/ansifilter/en/ansifilter.php
COMMENT=	Converts text containing terminal escape codes into markup
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c++

MAKE_FILE=	makefile
MAKEFLAGS+=	PREFIX=${PREFIX:Q}
MAKEFLAGS+=	man_dir=${PREFIX:Q}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
