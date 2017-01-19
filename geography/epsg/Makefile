# $NetBSD: Makefile,v 1.16 2017/01/19 18:52:11 agc Exp $
#

DISTNAME=		epsg-v${VERS}sql-PostgreSQL
PKGNAME=		epsg-${VERS_README}
VER_MAJOR=		8
VER_MINOR=		1
VERS=			${VER_MAJOR}_${VER_MINOR}
VERS_README=		${VER_MAJOR}.${VER_MINOR}
CATEGORIES=		geography databases
MASTER_SITES+=		http://www.epsg.org/databases/
MASTER_SITES+=		http://www.epsg.org/databases/Arc/${VERS}/
DISTFILES+=		epsg-v${VERS}sql-PostgreSQL.zip \
			epsg-v${VERS}sql-mySQL.zip
DIST_SUBDIR=		epsg-${VERS}

# Note some files are unpacked twice, once for PostgeSQL and once for
# mySQL.  We assume that they are the same and ignore the issue.

MAINTAINER=		brook@nmsu.edu
# MAINTAINER+=		gdt@NetBSD.org
HOMEPAGE=		http://www.epsg.org/
COMMENT=		EPSG geodetic parameters database
LICENSE=		epsg-license

WRKSRC=			${WRKDIR}

NO_BUILD=		yes

BINDIR=			${PREFIX}/bin
DOCDIR=			${PREFIX}/share/doc/epsg
EPSGDIR=		${PREFIX}/share/epsg

INSTALLATION_DIRS=	${BINDIR} ${DOCDIR} ${EPSGDIR}

MESSAGE_SUBST+=		BINDIR=${BINDIR:Q}
MESSAGE_SUBST+=		EPSGDIR=${EPSGDIR:Q}

# Upstream changes layout and file names for no apparent reason.

## directories
# 8.0, 8.3:
# pgsql files are in epsg-v${VERS}sql-PostgreSQL/,
# with mysql files in epsg-v${VERS}sql-mySQL/.

# 8.1:
# Files appear in the working directory itself.

DIR.doc=		
DIR.pgsql=		#epsg-v${VERS}sql-PostgreSQL
DIR.mysql=		#epsg-v${VERS}sql-mySQL

## file names
# 8.1:
# Files are named EPSG_v${VERS}.mdb_{Data,FKeys,Tables}_{PostgreSQL,MySQL}.sql

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
	${INSTALL_SCRIPT} ${WRKSRC}/epsg-load ${DESTDIR}${BINDIR}
	${INSTALL_DATA} ${WRKSRC}/${DIR.doc}/epsg-v${VERS_README}_readme.pdf ${DESTDIR}${DOCDIR:Q}
.for d in pgsql mysql
.for f in ${DATAFILES.${d}}
	${INSTALL_DATA} ${WRKSRC}/${DIR.${d}}/${f} ${DESTDIR}${EPSGDIR:Q}/${f}
.endfor
.endfor

.include "../../mk/bsd.pkg.mk"
