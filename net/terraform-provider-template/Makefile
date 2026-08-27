# $NetBSD: Makefile,v 1.62 2026/08/27 20:25:57 leot Exp $

DISTNAME=	terraform-provider-template-2.2.0
PKGREVISION=	60
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.terraform.io/docs/providers/template/
COMMENT=	Terraform template provider
LICENSE=	mpl-2.0

TERRAFORM_PROVIDER_BIN=		terraform-provider-template
TERRAFORM_PROVIDER_NAMESPACE=	hashicorp
TERRAFORM_PROVIDER_TYPE=	template

TERRAFORM_PROVIDER_LEGACY_INSTALL=	yes

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../net/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
