# $NetBSD: Makefile,v 1.12 2010/03/04 01:48:39 gdt Exp $
#

DISTNAME=		epsg-v${VERS}sql-PostgreSQL
PKGNAME=		epsg-7.4.1
VERS=			7_4_1
VERS_README=		7_4
CATEGORIES=		geography databases
MASTER_SITES+=		http://www.epsg.org/databases/ \
			http://www.epsg.org/databases/Arc/${VERS}/
DISTFILES+=		epsg-v${VERS}sql-PostgreSQL.zip \
			epsg-v${VERS}sql-mySQL.zip
DIST_SUBDIR=		epsg-${VERS}

MAINTAINER=		brook@nmsu.edu
HOMEPAGE=		http://www.epsg.org/
COMMENT=		EPSG geodetic parameters database
LICENSE=		epsg-license

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}

NO_BUILD=		yes

BINDIR=			${PREFIX}/bin
DOCDIR=			${PREFIX}/share/doc/epsg
EPSGDIR=		${PREFIX}/share/epsg

INSTALLATION_DIRS=	${BINDIR} ${DOCDIR} ${EPSGDIR}

MESSAGE_SUBST+=		BINDIR=${BINDIR:Q}
MESSAGE_SUBST+=		EPSGDIR=${EPSGDIR:Q}

DATAFILES.pgsql+=	EPSG_v${VERS}.mdb_Data_PostgreSQL.sql
DATAFILES.pgsql+=	EPSG_v${VERS}.mdb_FKeys_PostgreSQL.sql
DATAFILES.pgsql+=	EPSG_v${VERS}.mdb_Tables_PostgreSQL.sql

DATAFILES.mysql+=	EPSG_v${VERS}.mdb_Data_MySQL.sql
DATAFILES.mysql+=	EPSG_v${VERS}.mdb_FKeys_MySQL.sql
DATAFILES.mysql+=	EPSG_v${VERS}.mdb_Tables_MySQL.sql

SUBST_CLASSES+=		epsg
SUBST_STAGE.epsg=	do-configure
SUBST_FILES.epsg=	epsg-load
SUBST_VARS.epsg=	PREFIX EPSGDIR VERS
SUBST_MESSAGE.epsg=	Fixing EPSG example script

PLIST_SUBST+=		VERS=${VERS}
PLIST_SUBST+=		VERS_README=${VERS_README}

post-extract:
	${CP} ${FILESDIR}/epsg-load ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKSRC}/epsg-v${VERS_README}_readme.pdf ${DESTDIR}${DOCDIR:Q}
	${INSTALL_SCRIPT} ${WRKSRC}/epsg-load ${DESTDIR}${BINDIR}
.for d in pgsql mysql
.for f in ${DATAFILES.${d}}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${EPSGDIR:Q}/${f}
.endfor
.endfor

.include "../../mk/bsd.pkg.mk"
