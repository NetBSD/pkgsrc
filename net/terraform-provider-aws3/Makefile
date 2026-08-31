# $NetBSD: Makefile,v 1.2 2026/08/31 19:19:00 bsiegert Exp $

DISTNAME=	terraform-provider-aws-3.76.1
PKGNAME=	${DISTNAME:S/terraform-provider-aws/&3/}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
GITHUB_PROJECT=	terraform-provider-aws
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.terraform.io/docs/providers/aws/
COMMENT=	Terraform provider for Amazon Web Services
LICENSE=	mpl-2.0

# Previous net/terraform-provider-aws (3.x) did not have any version suffix
SUPERSEDES+=	terraform-provider-aws-[0-9]*

UNLIMIT_RESOURCES=	datasize virtualsize

TERRAFORM_PROVIDER_BIN=		terraform-provider-aws
TERRAFORM_PROVIDER_NAMESPACE=	hashicorp
TERRAFORM_PROVIDER_TYPE=	aws

TERRAFORM_PROVIDER_LEGACY_INSTALL=	yes

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../net/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
