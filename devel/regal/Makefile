# $NetBSD: Makefile,v 1.48 2026/02/24 08:45:26 bsiegert Exp $

DISTNAME=	regal-0.38.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=StyraOSS/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/StyraOSS/regal
COMMENT=	Linter for Rego
LICENSE=	apache-2.0

GOFLAGS+=		-ldflags ' \
			-X github.com/styrainc/regal/pkg/version.Version=${GITHUB_TAG} \
			-X github.com/styrainc/regal/pkg/version.Commit= \
			-X github.com/styrainc/regal/pkg/version.Timestamp= \
			-X github.com/styrainc/regal/pkg/version.Hostname='
GO_BUILD_PATTERN=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
