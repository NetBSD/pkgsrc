# $NetBSD: Makefile,v 1.19 2012/10/02 21:25:23 asau Exp $

DISTNAME=	psqlodbc-09.00.0200
PKGNAME=	odbc-postgresql-9.0.200
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL:=odbc/versions/src/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://pgfoundry.org/projects/psqlodbc/
COMMENT=	ODBC interface to PostgreSQL
LICENSE=	gnu-gpl-v2

CONFLICTS+=	postgresql-[0-7]*
CONFLICTS+=	iodbc-postgresql-[0-9]*
CONFLICTS+=	unixodbc-postgresql-[0-9]*

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-iodbc
CONFIGURE_ARGS+=	--without-unixodbc

INSTALLATION_DIRS=	share/doc/postgresql/odbc
INSTALLATION_DIRS+=	share/postgresql

post-install:
	${INSTALL_DATA} ${WRKSRC}/odbc.sql \
		${DESTDIR}${PREFIX}/share/postgresql/odbc.sql
	${INSTALL_DATA} ${WRKSRC}/odbc-drop.sql \
		${DESTDIR}${PREFIX}/share/postgresql/odbc-drop.sql
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DESTDIR}${PREFIX}/share/doc/postgresql/odbc/

.include "../../databases/iodbc/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
