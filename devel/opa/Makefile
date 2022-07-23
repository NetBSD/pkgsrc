# $NetBSD: Makefile,v 1.6 2022/07/23 18:50:10 leot Exp $

DISTNAME=	opa-0.42.2
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

pre-patch:
	${MV} ${WRKSRC}/runtime/check_user_darwin.go ${WRKSRC}/runtime/check_user_unix.go

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
