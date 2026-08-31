# $NetBSD: Makefile,v 1.2 2026/08/31 19:19:00 bsiegert Exp $

DISTNAME=	terraform-0.12.31
PKGNAME=	${DISTNAME:S/terraform/&012/}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
GITHUB_PROJECT=	terraform
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://www.terraform.io/
COMMENT=	Infrastructure orchestration tool
LICENSE=	mpl-2.0

# Previous net/terraform (0.12.x) did not have any version suffix
SUPERSEDES+=	terraform-[0-9]*

GO_BUILD_PATTERN=	.

WRKSRC=	${WRKDIR}/${DISTNAME}

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/terraform ${DESTDIR}${PREFIX}/bin/terraform012

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
