# $NetBSD: Makefile,v 1.67 2026/11/10 18:55:17 bsiegert Exp $

DISTNAME=	terraform-provider-archive-2.1.0
PKGREVISION=	65
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.terraform.io/docs/providers/archive/
COMMENT=	Terraform archive provider
LICENSE=	mpl-2.0

TERRAFORM_PROVIDER_BIN=		terraform-provider-archive
TERRAFORM_PROVIDER_NAMESPACE=	hashicorp
TERRAFORM_PROVIDER_TYPE=	archive

TERRAFORM_PROVIDER_LEGACY_INSTALL=	yes

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../net/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
