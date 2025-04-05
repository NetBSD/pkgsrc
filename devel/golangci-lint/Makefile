# $NetBSD: Makefile,v 1.46.2.1 2025/04/05 20:44:58 maya Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	golangci-lint-1.54.2
PKGREVISION=	15
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
