# $NetBSD: Makefile,v 1.25 2021/03/19 17:37:03 bsiegert Exp $

DISTNAME=	terraform-provider-aws-3.27.0
PKGREVISION=	1
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

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/terraform-provider-aws ${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
