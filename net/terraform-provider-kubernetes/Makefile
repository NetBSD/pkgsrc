# $NetBSD: Makefile,v 1.68 2026/05/07 18:50:02 bsiegert Exp $

DISTNAME=	terraform-provider-kubernetes-1.11.4
PKGREVISION=	61
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
GITHUB_PROJECT=	${PKGBASE}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://registry.terraform.io/providers/hashicorp/kubernetes/latest/docs
COMMENT=	Terraform provider for Kubernetes (K8S)
LICENSE=	mpl-2.0

UNLIMIT_RESOURCES=	datasize virtualsize

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/hashicorp/${GITHUB_PROJECT}

GO_BUILD_PATTERN=	${GO_SRCPATH}/.

USE_TOOLS+=	bash
REPLACE_BASH+=	scripts/*.sh

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
