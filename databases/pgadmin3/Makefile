# $NetBSD: Makefile,v 1.3 2006/07/22 04:46:15 rillig Exp $

DISTNAME=	pgadmin3-1.4.2
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${PGSQL_MIRRORS:=pgadmin3/release/v1.4.2/src/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.pgadmin.org/
COMMENT=	GUI administration tool for PostgreSQL RDBMS

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-pgsql=${PREFIX:Q}
CONFIGURE_ARGS+=	--with-pgsql-include=${PREFIX:Q}/include/postgresql
CONFIGURE_ARGS+=	--with-wx=${BUILDLINK_PREFIX.wxGTK:Q}

PGDIR=			${PREFIX}/share/pgadmin3

pre-install:
	${INSTALL_DATA_DIR} ${PGDIR:Q}/docs/de_DE/hints
	${INSTALL_DATA_DIR} ${PGDIR:Q}/docs/en_US/hints
	${INSTALL_DATA_DIR} ${PGDIR:Q}/docs/en_US/images
	${INSTALL_DATA_DIR} ${PGDIR:Q}/docs/en_US/pg
	${INSTALL_DATA_DIR} ${PGDIR:Q}/docs/en_US/slony
	${INSTALL_DATA_DIR} ${PGDIR:Q}/docs/es_ES/hints
	${INSTALL_DATA_DIR} ${PGDIR:Q}/docs/fr_FR/hints
	${INSTALL_DATA_DIR} ${PGDIR:Q}/docs/sl_SI/hints
	${INSTALL_DATA_DIR} ${PGDIR:Q}/ui

.include "../../databases/postgresql81/Makefile.mirrors"
.include "../../x11/wxGTK-contrib/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
