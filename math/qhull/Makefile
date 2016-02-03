# $NetBSD: Makefile,v 1.5 2016/02/03 16:05:56 nros Exp $

DISTNAME=	qhull-2015-src-7.2.0
PKGNAME=	qhull-2015.2
CATEGORIES=	math
MASTER_SITES=	http://www.qhull.org/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.qhull.org/
COMMENT=	Computing the convex hull

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_USE_GNU_INSTALL_DIRS = no
CMAKE_ARGS+=	-DMAN_INSTALL_DIR:PATH=${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
