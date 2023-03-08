# $NetBSD: Makefile,v 1.50 2023/03/08 13:38:46 bsiegert Exp $

DISTNAME=	terraform-provider-aws-3.27.0
PKGREVISION=	25
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=terraform-providers/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.terraform.io/docs/providers/aws/
COMMENT=	Terraform provider for Amazon Web Services
LICENSE=	mpl-2.0

DEPENDS+=	terraform-[0-9]*:../../net/terraform

GO_BUILD_PATTERN=	.

UNLIMIT_RESOURCES=	datasize virtualsize

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
