# $NetBSD: Makefile,v 1.48 2024/02/07 14:50:55 bsiegert Exp $

DISTNAME=	terraform-provider-kubernetes-1.11.4
PKGREVISION=	42
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
GITHUB_PROJECT=	${PKGBASE}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.terraform.io/docs/providers/kubernetes/
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
