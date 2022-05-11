# $NetBSD: Makefile,v 1.6 2022/05/11 19:26:27 bsiegert Exp $

DISTNAME=	conftest-0.31.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=open-policy-agent/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://www.conftest.dev/
COMMENT=	Tests structured configuration data via OPA Rego query language
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/open-policy-agent/conftest/internal/commands.version=${GITHUB_TAG}' \
			.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
