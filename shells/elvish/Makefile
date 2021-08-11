# $NetBSD: Makefile,v 1.2 2021/08/11 19:35:09 bsiegert Exp $

DISTNAME=	elvish-0.15.0
PKGREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=elves/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	mj@mjturner.net
HOMEPAGE=	https://elv.sh/
COMMENT=	Expressive programming language and a versatile interactive shell
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/${DISTNAME}

GO_VERSION_DEFAULT=	115

INSTALLATION_DIRS=	bin
PKG_SHELL=		bin/elvish

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/elvish ${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
