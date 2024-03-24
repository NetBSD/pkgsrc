# $NetBSD: Makefile,v 1.46 2024/03/24 18:48:59 leot Exp $

DISTNAME=	conftest-0.50.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=open-policy-agent/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://www.conftest.dev/
COMMENT=	Tests structured configuration data via OPA Rego query language
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/open-policy-agent/conftest/internal/commands.version=${GITHUB_TAG}'
GO_BUILD_PATTERN+=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
