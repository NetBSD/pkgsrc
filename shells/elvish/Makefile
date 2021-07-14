# $NetBSD: Makefile,v 1.1 2021/07/14 20:51:27 pin Exp $

DISTNAME=	elvish-0.15.0
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
