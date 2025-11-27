# $NetBSD: Makefile,v 1.43 2025/11/27 09:45:15 leot Exp $

DISTNAME=	regal-0.37.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=StyraOSS/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/StyraOSS/regal
COMMENT=	Linter for Rego
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/styrainc/regal/pkg/version.Version=${GITHUB_TAG} \
			-X github.com/styrainc/regal/pkg/version.Commit= \
			-X github.com/styrainc/regal/pkg/version.Timestamp= \
			-X github.com/styrainc/regal/pkg/version.Hostname='

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
