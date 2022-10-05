# $NetBSD: Makefile,v 1.30 2022/10/05 11:33:04 bsiegert Exp $

DISTNAME=	terraform-provider-vultr-2.11.3
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=vultr/}
GITHUB_PROJECT=	${PKGBASE}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.terraform.io/docs/providers/vultr/
COMMENT=	Terraform provider for Vultr
LICENSE=	mpl-2.0

DEPENDS+=	terraform-[0-9]*:../../net/terraform

UNLIMIT_RESOURCES=	datasize virtualsize

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/vultr/${GITHUB_PROJECT}

GO_BUILD_PATTERN=	${GO_SRCPATH}/.

USE_TOOLS+=	bash
REPLACE_BASH+=	scripts/*.sh

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
