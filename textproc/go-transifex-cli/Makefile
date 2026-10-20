# $NetBSD: Makefile,v 1.7 2026/10/20 20:28:20 bsiegert Exp $
#

DISTNAME=	cli-${VERS}
PKGNAME=	go-transifex-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=transifex/}
GITHUB_PROJECT=	cli
GITHUB_TAG=	v${VERS}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/transifex/cli
COMMENT=	Command line interface for Transifex
LICENSE=	apache-2.0

VERS=		1.6.17

.include "go-modules.mk"

pre-install:
	cd ${WRKDIR}/.gopath/bin && ${MV} cli tx

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
