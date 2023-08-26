# $NetBSD: Makefile,v 1.32 2023/08/26 16:31:24 bsiegert Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	errcheck-1.6.2
PKGREVISION=	11
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
