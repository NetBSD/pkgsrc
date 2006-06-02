# $NetBSD: Makefile,v 1.1.1.1 2006/06/02 15:05:16 adam Exp $

DISTNAME=	slony1-1.1.5
CATEGORIES=	databases
MASTER_SITES=	http://developer.postgresql.org/~wieck/slony1/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://gborg.postgresql.org/project/slony1/
COMMENT=	Replication system for PostgreSQL

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-pgconfigdir=${PGSQL_PREFIX:Q}/bin
CONFIGURE_ARGS+=	--with-pgbindir=${PGSQL_PREFIX:Q}/bin
CONFIGURE_ARGS+=	--with-pgincludedir=${PGSQL_PREFIX:Q}/include/postgresql
CONFIGURE_ARGS+=	--with-pgincludeserverdir=${PGSQL_PREFIX:Q}/include/postgresql/server
CONFIGURE_ARGS+=	--with-pglibdir=${PGSQL_PREFIX:Q}/lib
CONFIGURE_ARGS+=	--with-pgpkglibdir=${PGSQL_PREFIX:Q}/lib/postgresql
CONFIGURE_ARGS+=	--with-pgsharedir=${PGSQL_PREFIX:Q}/share/postgresql

post-install:
	${INSTALL_DATA} ${WRKSRC}/share/slon.conf-sample \
		${PGSQL_PREFIX:Q}/share/postgresql

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
