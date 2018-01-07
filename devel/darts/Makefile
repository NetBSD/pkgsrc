# $NetBSD: Makefile,v 1.10 2018/01/07 21:16:05 rillig Exp $

DISTNAME=	darts-0.32
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://chasen.org/~taku/software/darts/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://chasen.org/~taku/software/darts/
COMMENT=	C++ template library that implements Double-Array
LICENSE=	gnu-lgpl-v2.1 OR modified-bsd

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
AUTO_MKDIRS=	yes

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS ChangeLog README \
		${DESTDIR}${PREFIX}/share/doc/darts
	cd ${WRKSRC}/doc && ${INSTALL_DATA} darts.css index.html \
		${DESTDIR}${PREFIX}/share/doc/darts
	cd ${WRKSRC} && ${INSTALL_DATA} darts.cpp mkdarts.cpp \
		${DESTDIR}${PREFIX}/share/examples/darts

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
