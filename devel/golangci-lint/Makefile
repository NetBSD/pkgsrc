# $NetBSD: Makefile,v 1.27 2023/03/08 13:38:56 bsiegert Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	golangci-lint-1.33.0
PKGREVISION=	26
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
