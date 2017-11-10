# $NetBSD: Makefile,v 1.1 2017/11/10 15:07:02 fhajny Exp $

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

USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	share/doc/redislog

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${DESTDIR}${PREFIX}/share/doc/redislog

.include "../../databases/hiredis/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
