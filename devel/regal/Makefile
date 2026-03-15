# $NetBSD: Makefile,v 1.50 2026/03/15 11:46:22 leot Exp $

DISTNAME=	regal-0.39.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=open-policy-agent/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/open-policy-agent/regal
COMMENT=	Linter for Rego
LICENSE=	apache-2.0

GOFLAGS+=		-ldflags ' \
			-X github.com/open-policy-agent/regal/pkg/version.Version=${GITHUB_TAG} \
			-X github.com/open-policy-agent/regal/pkg/version.Commit= \
			-X github.com/open-policy-agent/regal/pkg/version.Timestamp= \
			-X github.com/open-policy-agent/regal/pkg/version.Hostname='
GO_BUILD_PATTERN=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
