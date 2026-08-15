# $NetBSD: Makefile,v 1.41 2026/08/15 12:53:17 bsiegert Exp $

DISTNAME=	sqlc-1.31.1
GITHUB_TAG=	v${PKGVERSION_NOREV}
PKGREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=sqlc-dev/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://sqlc.dev/
COMMENT=	Generate type-safe code from SQL
LICENSE=	mit

USE_LANGUAGES=		c c++ # go
GO_BUILD_PATTERN=	./cmd/sqlc

BROKEN_EXCEPT_ON_PLATFORM+=	Darwin-[0-9]* Linux-[0-9]*

.include "go-modules.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/sqlc \
	  ${DESTDIR}${PREFIX}/bin/sqlc

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
