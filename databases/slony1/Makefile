# $NetBSD: Makefile,v 1.34 2026/10/10 19:51:35 wiz Exp $

DISTNAME=	slony1-2.2.11
CATEGORIES=	databases
MASTER_SITES=	http://slony.info/downloads/${PKGVERSION_NOREV:R}/source/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://slony.info/
COMMENT=	Replication system for PostgreSQL
LICENSE=	postgresql-license

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

# missing 64-bit type when compiled with postgresql 18
# documented as of 2.2.11 (2022) is support for 15
PGSQL_VERSIONS_ACCEPTED=	17 16 15 14

CFLAGS+=	-Wno-int-conversion

post-extract:
	${CP} ${WRKSRC}/makefiles/Makefile.freebsd ${WRKSRC}/makefiles/Makefile.dragonfly

post-install:
	${INSTALL_DATA} ${WRKSRC}/share/slon.conf-sample \
		${DESTDIR}${PGSQL_PREFIX}/share/postgresql

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
