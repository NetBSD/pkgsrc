# $NetBSD: Makefile,v 1.1 2025/09/07 18:26:00 maya Exp $

DISTNAME=	helm-3.18.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=helm/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://helm.sh/
COMMENT=	The Kubernetes Package Manager
LICENSE=	apache-2.0

# XXX: via: `cd ${WRKSRC} && go list -f '{{.Version}}' -m k8s.io/client-go`
K8S_MODULES_VERSION=		0.33.2 # <major>.<minor>.x
K8S_MODULES_VERSION_MAJOR=	1 # <major> + 1
K8S_MODULES_VERSION_MINOR=	33 # <minor>
GO_BUILD_PATTERN+=	-ldflags ' \
			-X helm.sh/helm/v3/internal/version.version=${PKGVERSION_NOREV} \
			-X helm.sh/helm/v3/internal/version.metadata= \
			-X helm.sh/helm/v3/internal/version.gitCommit= \
			-X helm.sh/helm/v3/internal/version.gitTreeState= \
			-X helm.sh/helm/v3/pkg/lint/rules.k8sVersionMajor=${K8S_MODULES_VERSION_MAJOR} \
			-X helm.sh/helm/v3/pkg/lint/rules.k8sVersionMinor=${K8S_MODULES_VERSION_MINOR} \
			-X helm.sh/helm/v3/pkg/chartutil.k8sVersionMajor=${K8S_MODULES_VERSION_MAJOR} \
			-X helm.sh/helm/v3/pkg/chartutil.k8sVersionMinor=${K8S_MODULES_VERSION_MINOR}'
GO_BUILD_PATTERN+=	./cmd/helm

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
