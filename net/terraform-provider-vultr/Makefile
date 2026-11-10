# $NetBSD: Makefile,v 1.77 2026/11/10 18:55:18 bsiegert Exp $

DISTNAME=	terraform-provider-vultr-2.30.1
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=vultr/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.terraform.io/docs/providers/vultr/
COMMENT=	Terraform Vultr provider
LICENSE=	mpl-2.0

GO_BUILD_PATTERN=	.

TERRAFORM_PROVIDER_BIN=		terraform-provider-vultr
TERRAFORM_PROVIDER_NAMESPACE=	vultr
TERRAFORM_PROVIDER_TYPE=	vultr

TERRAFORM_PROVIDER_LEGACY_INSTALL=	yes

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../net/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
