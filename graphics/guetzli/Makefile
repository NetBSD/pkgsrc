# $NetBSD: Makefile,v 1.2 2017/03/17 14:51:25 adam Exp $

DISTNAME=	guetzli-1.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/google/guetzli
COMMENT=	JPEG encoder with great compression at high quality
LICENSE=	apache-2.0

GITHUB_TAG=	v${PKGVERSION_NOREV}

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin share/doc/guetzli

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/Release/guetzli ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/guetzli

.include "../../devel/gflags/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
