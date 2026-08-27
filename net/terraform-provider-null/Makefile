# $NetBSD: Makefile,v 1.72 2026/08/27 20:24:26 leot Exp $

DISTNAME=	terraform-provider-null-3.0.0
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
.include "../../wip/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
