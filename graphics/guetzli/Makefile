# $NetBSD: Makefile,v 1.5 2020/04/12 06:51:09 adam Exp $

DISTNAME=	guetzli-1.0.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/guetzli
COMMENT=	JPEG encoder with great compression at high quality
LICENSE=	apache-2.0

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake pkg-config

INSTALLATION_DIRS=	bin share/doc/guetzli

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/Release/guetzli ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/guetzli

.include "../../devel/gflags/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
