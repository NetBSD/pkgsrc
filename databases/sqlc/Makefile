# $NetBSD: Makefile,v 1.23 2025/03/09 20:06:43 bsiegert Exp $

DISTNAME=	sqlc-1.28.0
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=sqlc-dev/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://sqlc.dev/
COMMENT=	Generate type-safe code from SQL
LICENSE=	mit

USE_LANGUAGES=		c c++ # go
GO_BUILD_PATTERN=	./cmd/sqlc

.include "go-modules.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/sqlc \
	  ${DESTDIR}${PREFIX}/bin/sqlc

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
