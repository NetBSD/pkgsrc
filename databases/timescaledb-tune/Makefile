# $NetBSD: Makefile,v 1.3 2021/07/13 11:36:36 bsiegert Exp $

DISTNAME=	timescaledb-tune-0.11.0.20210308
MASTER_SITES=	${MASTER_SITE_GITHUB:=timescale/}
PKGREVISION=	1
CATEGORIES=	databases
# need git master for proper PostgreSQL 13 support
#GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_TAG=	f6b74b85e3378b1b07e363daf89a8fe1d388c665

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/timescale/timescaledb-tune
COMMENT=	Tune timescaledb to match system's CPU and memory resources
LICENSE=	apache-2.0

.include "go-modules.mk"

GO_BUILD_PATTERN=	./cmd/timescaledb-tune/...
INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/timescaledb-tune	\
	  ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
