# $NetBSD: Makefile,v 1.5 2025/05/30 21:51:23 tnn Exp $

DISTNAME=	ansifilter-2.21
CATEGORIES=	textproc
MASTER_SITES=	http://andre-simon.de/zip/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://andre-simon.de/doku/ansifilter/en/ansifilter.php
COMMENT=	Converts text containing terminal escape codes into markup
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++17

MAKE_FILE=	makefile
MAKE_FLAGS+=	PREFIX=${PREFIX:Q}
MAKE_FLAGS+=	man_dir=${PREFIX:Q}/${PKGMANDIR}/man1

#BUILDLINK_TRANSFORM.NetBSD+=	rm:-ldl
#.include "../../devel/cmake/build.mk"
#.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
