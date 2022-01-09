# $NetBSD: Makefile,v 1.8 2022/01/09 20:10:38 bsiegert Exp $

DISTNAME=	elvish-0.16.1
PKGREVISION=	4
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=elves/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	mj@mjturner.net
HOMEPAGE=	https://elv.sh/
COMMENT=	Expressive programming language and a versatile interactive shell
LICENSE=	2-clause-bsd

INSTALLATION_DIRS=	bin
PKG_SHELL=		bin/elvish
GO_BUILD_PATTERN=	./...

# needed for the tests
USE_TOOLS+=		perl

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/elvish ${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
