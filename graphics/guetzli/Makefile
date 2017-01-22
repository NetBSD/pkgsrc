# $NetBSD: Makefile,v 1.1 2017/01/22 10:32:50 wiz Exp $

DISTNAME=	guetzli-0.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/google/guetzli
COMMENT=	JPEG encoder with great compression at high quality
LICENSE=	apache-2.0

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin share/doc/guetzli

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/Release/guetzli ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/guetzli

.include "../../devel/gflags/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
