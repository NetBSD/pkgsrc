# $NetBSD: Makefile,v 1.74 2026/08/31 19:19:00 bsiegert Exp $

DISTNAME=	terraform-provider-null-3.0.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.terraform.io/docs/providers/null/
COMMENT=	Terraform provider for nothing
LICENSE=	mpl-2.0

TERRAFORM_PROVIDER_BIN=		terraform-provider-null
TERRAFORM_PROVIDER_NAMESPACE=	hashicorp
TERRAFORM_PROVIDER_TYPE=	null

TERRAFORM_PROVIDER_LEGACY_INSTALL=	yes

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../net/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
