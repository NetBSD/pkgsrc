# $NetBSD: Makefile,v 1.64 2026/05/07 18:50:00 bsiegert Exp $

DISTNAME=	kubectl-1.22.17
PKGREVISION=	33
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=kubernetes/}
GITHUB_PROJECT=	kubernetes
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/kubernetes/kubectl
COMMENT=	Command line tool lets you control Kubernetes clusters
LICENSE=	apache-2.0

GOFLAGS+=		-ldflags ' \
			-X k8s.io/client-go/pkg/version.buildDate="" \
			-X k8s.io/client-go/pkg/version.gitTreeState=clean \
			-X k8s.io/client-go/pkg/version.gitVersion=v${PKGVERSION_NOREV} \
			-X k8s.io/component-base/version.buildDate="" \
			-X k8s.io/component-base/version.gitMajor=${PKGVERSION_NOREV:C/\..*//} \
			-X k8s.io/component-base/version.gitMinor=${PKGVERSION_NOREV:C/[0-9]+\.//:C/\..*//} \
			-X k8s.io/component-base/version.gitTreeState=clean \
			-X k8s.io/component-base/version.gitVersion=v${PKGVERSION_NOREV}'
GOFLAGS+=		-mod=readonly
GO_BUILD_PATTERN=	./cmd/kubectl

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
