# $NetBSD: Makefile,v 1.6 2026/05/07 18:49:53 bsiegert Exp $

DISTNAME=	golds-0.8.2
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=go101/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/go101/golds/
COMMENT=	Go local docs server/generator and code reader
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LANGUAGES=	c # go

GO_BUILD_PATTERN=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
