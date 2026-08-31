# $NetBSD: Makefile,v 1.2 2026/08/31 19:19:00 bsiegert Exp $

DISTNAME=	terraform-provider-random-2.3.0
PKGNAME=	${DISTNAME:S/terraform-provider-random/&2/}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
GITHUB_PROJECT=	terraform-provider-random
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.terraform.io/docs/providers/random/
COMMENT=	Terraform provider for randomness
LICENSE=	mpl-2.0

# Previous net/terraform-provider-random (2.x) did not have any version suffix
SUPERSEDES+=	terraform-provider-random-[0-9]*

TERRAFORM_PROVIDER_BIN=		terraform-provider-random
TERRAFORM_PROVIDER_NAMESPACE=	hashicorp
TERRAFORM_PROVIDER_TYPE=	random

TERRAFORM_PROVIDER_LEGACY_INSTALL=	yes

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../net/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
