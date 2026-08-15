# $NetBSD: Makefile,v 1.18 2026/08/15 12:53:29 bsiegert Exp $

DISTNAME=	cli-0.37.0
PKGNAME=	tektoncd-${DISTNAME}
PKGREVISION=	17
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=tektoncd/}
GITHUB_PROJECT=	cli
GITHUB_TAG=	v${PKGVERSION_NOREV}
DIST_SUBDIR=	tekton

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tekton.dev/vault/cli-main/
COMMENT=	Command line client for interacting with Tekton components
LICENSE=	apache-2.0

USE_LANGUAGES=	c
USE_TOOLS+=	gmake

GO_VERSION_REQD+=	122

WRKSRC=		${WRKDIR}/${DISTNAME}

GO_BUILD_PATTERN=	./cmd/tkn

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
