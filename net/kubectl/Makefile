# $NetBSD: Makefile,v 1.6 2021/08/07 10:55:50 leot Exp $

DISTNAME=	kubectl-1.20.9
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=kubernetes/}
GITHUB_PROJECT=	kubernetes
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kubernetes/kubectl
COMMENT=	Command line tool lets you control Kubernetes clusters
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X k8s.io/client-go/pkg/version.buildDate="" \
			-X k8s.io/client-go/pkg/version.gitTreeState=clean \
			-X k8s.io/client-go/pkg/version.gitVersion=v${PKGVERSION_NOREV} \
			-X k8s.io/component-base/version.buildDate="" \
			-X k8s.io/component-base/version.gitMajor=${PKGVERSION_NOREV:C/\..*//} \
			-X k8s.io/component-base/version.gitMinor=${PKGVERSION_NOREV:C/[0-9]+\.//:C/\..*//} \
			-X k8s.io/component-base/version.gitTreeState=clean \
			-X k8s.io/component-base/version.gitVersion=v${PKGVERSION_NOREV}'
GO_BUILD_PATTERN+=	./cmd/kubectl

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
