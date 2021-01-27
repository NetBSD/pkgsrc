# $NetBSD: Makefile,v 1.16 2021/01/27 13:35:58 leot Exp $

DISTNAME=	terraform-0.12.30
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.terraform.io/
COMMENT=	Infrastructure orchestration tool
LICENSE=	mpl-2.0

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/hashicorp/terraform

GO_BUILD_PATTERN=	${GO_SRCPATH}/.

# Not actually sure these are used.
USE_TOOLS+=	bash
REPLACE_BASH+=	command/e2etest/make-archive.sh
REPLACE_BASH+=	scripts/debug-terraform
REPLACE_BASH+=	scripts/*.sh
REPLACE_BASH+=	scripts/*/*.sh

CHECK_RELRO_SKIP+=	bin/terraform

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
