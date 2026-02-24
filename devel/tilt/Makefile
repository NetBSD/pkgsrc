# $NetBSD: Makefile,v 1.2 2026/02/24 08:45:27 bsiegert Exp $

DISTNAME=	tilt-0.36.3
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=tilt-dev/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tilt.dev/
COMMENT=	Microservice development environment tool
LICENSE=	apache-2.0

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS=		gmake

DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs
DEPENDS+=	yarn-[0-9]*:../../devel/yarn

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
