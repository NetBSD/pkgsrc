# $NetBSD: Makefile,v 1.24 2026/10/20 20:28:08 bsiegert Exp $

DISTNAME=	helm-4.2.3
PKGREVISION=	6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=helm/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://helm.sh/
COMMENT=	The Kubernetes Package Manager
LICENSE=	apache-2.0

GOFLAGS+=	-ldflags '-s -w \
		-X helm.sh/helm/v3/internal/version.version=${PKGVERSION_NOREV} \
		-X helm.sh/helm/v3/internal/version.metadata= \
		-X helm.sh/helm/v3/internal/version.gitCommit= \
		-X helm.sh/helm/v3/internal/version.gitTreeState='

GO_BUILD_PATTERN=	./cmd/helm

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
