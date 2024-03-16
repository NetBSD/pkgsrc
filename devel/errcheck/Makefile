# $NetBSD: Makefile,v 1.41 2024/03/16 17:21:02 bsiegert Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	errcheck-1.7.0
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
