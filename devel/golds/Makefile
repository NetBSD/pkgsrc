# $NetBSD: Makefile,v 1.10 2026/08/22 15:19:00 bsiegert Exp $

DISTNAME=	golds-0.8.2
PKGREVISION=	9
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
