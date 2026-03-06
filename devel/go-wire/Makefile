# $NetBSD: Makefile,v 1.48 2026/03/06 21:07:49 bsiegert Exp $

DISTNAME=	go-wire-0.7.0
PKGREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_PROJECT=	wire
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/wire
COMMENT=	Compile-time Dependency Injection for Go
LICENSE=	apache-2.0

.include "go-modules.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/wire	\
	  ${DESTDIR}${PREFIX}/bin/wire

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
