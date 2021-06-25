# $NetBSD: Makefile,v 1.2 2021/06/25 16:01:46 tnn Exp $

DISTNAME=	timescaledb-tune-0.11.0.20210308
MASTER_SITES=	${MASTER_SITE_GITHUB:=timescale/}
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
