# $NetBSD: Makefile,v 1.12 2022/01/09 20:10:30 bsiegert Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	golangci-lint-1.33.0
PKGREVISION=	11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=golangci/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://golangci-lint.run/
COMMENT=	Aggregator for Go linters
LICENSE=	gnu-gpl-v3

GO_BUILD_PATTERN=	./cmd/golangci-lint

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
