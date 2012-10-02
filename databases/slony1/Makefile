# $NetBSD: Makefile,v 1.21 2012/10/02 21:25:53 asau Exp $

DISTNAME=	slony1-2.1.0
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://slony.info/downloads/2.1/source/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://main.slony.info/
COMMENT=	Replication system for PostgreSQL

PGSQL_VERSIONS_ACCEPTED=91 90 84 83

DEPENDS+=	postgresql${PGSQL_VERSION}-server-[0-9]*:../../databases/postgresql${PGSQL_VERSION}-server

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-pgconfigdir=${PGSQL_PREFIX}/bin
CONFIGURE_ARGS+=	--with-pgbindir=${PGSQL_PREFIX}/bin
CONFIGURE_ARGS+=	--with-pgincludedir=${PGSQL_PREFIX}/include/postgresql
CONFIGURE_ARGS+=	--with-pgincludeserverdir=${PGSQL_PREFIX}/include/postgresql/server
CONFIGURE_ARGS+=	--with-pglibdir=${PGSQL_PREFIX}/lib
CONFIGURE_ARGS+=	--with-pgpkglibdir=${PGSQL_PREFIX}/lib/postgresql
CONFIGURE_ARGS+=	--with-pgsharedir=${PGSQL_PREFIX}/share/postgresql
MAKE_FILE=		GNUmakefile

post-extract:
	cp ${WRKSRC}/makefiles/Makefile.freebsd ${WRKSRC}/makefiles/Makefile.dragonfly

post-install:
	${INSTALL_DATA} ${WRKSRC}/share/slon.conf-sample \
	    ${DESTDIR}${PGSQL_PREFIX}/share/postgresql

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
