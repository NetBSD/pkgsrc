# $NetBSD: Makefile,v 1.16 2024/06/01 14:02:49 bsiegert Exp $

DISTNAME=	sqlc-1.16.0
GITHUB_TAG=	v${PKGVERSION_NOREV}
PKGREVISION=	14
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=kyleconroy/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://sqlc.dev/
COMMENT=	Generate type-safe code from SQL
LICENSE=	mit

USE_LANGUAGES=		c # go

GO_MODULE_EXTRACT+=	github.com_pganalyze_pg_query_go_v2_@v_v2.2.0.zip

GO_BUILD_PATTERN=	./cmd/sqlc

.include "go-modules.mk"

#INSTALLATION_DIRS=	bin

#do-install:
#	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/sqlc \
#	  ${DESTDIR}${PREFIX}/bin/sqlc

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
