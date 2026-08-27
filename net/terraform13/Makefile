# $NetBSD: Makefile,v 1.1 2026/08/27 20:40:18 leot Exp $

DISTNAME=	terraform-1.3.10
PKGNAME=	${DISTNAME:S/terraform/&13/}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
GITHUB_PROJECT=	terraform
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://www.terraform.io/
COMMENT=	Infrastructure orchestration tool
LICENSE=	mpl-2.0

GO_BUILD_PATTERN=	.

SUBST_CLASSES+=			providers-prefix
SUBST_STAGE.providers-prefix=	pre-configure
SUBST_MESSAGE.providers-prefix=	Honor providers installed via pkgsrc
SUBST_FILES.providers-prefix=	provider_source.go
SUBST_VARS.providers-prefix=	PREFIX

WRKSRC=	${WRKDIR}/${DISTNAME}

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/terraform ${DESTDIR}${PREFIX}/bin/terraform13

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
