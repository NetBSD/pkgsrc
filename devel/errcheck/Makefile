# $NetBSD: Makefile,v 1.69 2026/10/20 20:27:59 bsiegert Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	errcheck-1.9.0
PKGREVISION=	18
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=kisielk/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/kisielk/errcheck/
COMMENT=	Check for unchecked errors in Go programs
LICENSE=	mit

GO_BUILD_PATTERN=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
