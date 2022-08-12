# $NetBSD: Makefile,v 1.10 2022/08/12 20:38:11 bsiegert Exp $

DISTNAME=	go-wire-0.5.0.20210831
PKGREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_PROJECT=	wire
GITHUB_TAG=	2f70a008e2446b941cdeadb751ed6979ec49a29c

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
