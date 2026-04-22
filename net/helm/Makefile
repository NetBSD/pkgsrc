# $NetBSD: Makefile,v 1.10.2.1 2026/04/22 14:32:07 maya Exp $

DISTNAME=	helm-3.18.6
PKGREVISION=	7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=helm/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://helm.sh/
COMMENT=	The Kubernetes Package Manager
LICENSE=	apache-2.0

# XXX: To get K8S_MODULES_VERSION:
# XXX:  $ make build-env
# XXX:  $ go list -f '{{.Version}}' -m k8s.io/client-go
K8S_MODULES_VERSION=		0.33.3 # <major>.<minor>.x
K8S_MODULES_VERSION_MAJOR=	1 # <major> + 1
K8S_MODULES_VERSION_MINOR=	33 # <minor>
GOFLAGS+=		-ldflags ' \
			-X helm.sh/helm/v3/internal/version.version=${PKGVERSION_NOREV} \
			-X helm.sh/helm/v3/internal/version.metadata= \
			-X helm.sh/helm/v3/internal/version.gitCommit= \
			-X helm.sh/helm/v3/internal/version.gitTreeState= \
			-X helm.sh/helm/v3/pkg/lint/rules.k8sVersionMajor=${K8S_MODULES_VERSION_MAJOR} \
			-X helm.sh/helm/v3/pkg/lint/rules.k8sVersionMinor=${K8S_MODULES_VERSION_MINOR} \
			-X helm.sh/helm/v3/pkg/chartutil.k8sVersionMajor=${K8S_MODULES_VERSION_MAJOR} \
			-X helm.sh/helm/v3/pkg/chartutil.k8sVersionMinor=${K8S_MODULES_VERSION_MINOR}'
GO_BUILD_PATTERN=	./cmd/helm

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
