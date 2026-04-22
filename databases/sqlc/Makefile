# $NetBSD: Makefile,v 1.35.2.1 2026/04/22 14:31:56 maya Exp $

DISTNAME=	sqlc-1.30.0
GITHUB_TAG=	v${PKGVERSION_NOREV}
PKGREVISION=	4
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
