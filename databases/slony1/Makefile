# $NetBSD: Makefile,v 1.8 2008/01/14 18:58:02 adam Exp $

DISTNAME=	slony1-1.2.12
CATEGORIES=	databases
MASTER_SITES=	http://slony.info/downloads/1.2/source/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://main.slony.info/
COMMENT=	Replication system for PostgreSQL

DEPENDS+=	postgresql${PGSQL_VERSION}-server-[0-9]*:../../databases/postgresql${PGSQL_VERSION}-server

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-pgconfigdir=${PGSQL_PREFIX:Q}/bin
CONFIGURE_ARGS+=	--with-pgbindir=${PGSQL_PREFIX:Q}/bin
CONFIGURE_ARGS+=	--with-pgincludedir=${PGSQL_PREFIX:Q}/include/postgresql
CONFIGURE_ARGS+=	--with-pgincludeserverdir=${PGSQL_PREFIX:Q}/include/postgresql/server
CONFIGURE_ARGS+=	--with-pglibdir=${PGSQL_PREFIX:Q}/lib
CONFIGURE_ARGS+=	--with-pgpkglibdir=${PGSQL_PREFIX:Q}/lib/postgresql
CONFIGURE_ARGS+=	--with-pgsharedir=${PGSQL_PREFIX:Q}/share/postgresql

post-extract:
	cp ${WRKSRC}/makefiles/Makefile.freebsd ${WRKSRC}/makefiles/Makefile.dragonfly

post-install:
	${INSTALL_DATA} ${WRKSRC}/share/slon.conf-sample \
		${PGSQL_PREFIX:Q}/share/postgresql

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
