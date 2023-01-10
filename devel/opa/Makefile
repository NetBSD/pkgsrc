# $NetBSD: Makefile,v 1.18 2023/01/10 11:07:14 leot Exp $

DISTNAME=	opa-0.48.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=open-policy-agent/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://www.openpolicyagent.org/
COMMENT=	Open source, general-purpose policy engine
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/open-policy-agent/opa/version.Version=${PKGVERSION_NOREV} \
			-X github.com/open-policy-agent/opa/version.Vcs= \
			-X github.com/open-policy-agent/opa/version.Timestamp= \
			-X github.com/open-policy-agent/opa/version.Hostname= \
			-X github.com/open-policy-agent/opa/internal/report.ExternalServiceURL='

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
