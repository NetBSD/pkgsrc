# $NetBSD: Makefile,v 1.3 2023/03/09 06:07:04 wiz Exp $

DISTNAME=	redislog-0.2
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=2ndquadrant-it/}

GITHUB_PROJECT=	redislog
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/2ndquadrant-it/redislog/
COMMENT=	Shipping PostgreSQL logs to Redis
LICENSE=	mit

DEPENDS+=	postgresql${PGSQL_VERSION}-server>=0:../../databases/postgresql${PGSQL_VERSION}-server

# redislog.c:185:20: error: static declaration of 'error_severity' follows non-static declaration
PGSQL_VERSIONS_ACCEPTED=	14 13 12 11

USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	share/doc/redislog

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${DESTDIR}${PREFIX}/share/doc/redislog

.include "../../databases/hiredis/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
