# $NetBSD: Makefile,v 1.6 2006/10/29 00:15:43 wiz Exp $
#

DISTNAME=		epsg-v${VERS}sql-PostgreSQL
PKGNAME=		epsg-6.11.2
VERS=			6_11_2
CATEGORIES=		geography databases
MASTER_SITES+=		http://www.epsg.org/databases/
DISTFILES+=		epsg-v${VERS}sql-PostgreSQL.zip \
			epsg-v${VERS}sql-mySQL.zip \
			G7-1.pdf G7-2.pdf
EXTRACT_ONLY=		epsg-v${VERS}sql-PostgreSQL.zip \
			epsg-v${VERS}sql-mySQL.zip
DIST_SUBDIR=		epsg-20061029

MAINTAINER=		brook@nmsu.edu
HOMEPAGE=		http://www.epsg.org/
COMMENT=		EPSG Geodetic Parameters database

# don't make filenames lowercase
EXTRACT_OPTS_ZIP=	-aqo

LICENSE=		epsg-license
RESTRICTED=		No commercial redistribution
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

SITES.G7-1.pdf=		http://www.epsg.org/guides/docs/
SITES.G7-2.pdf=		${SITES.G7-1.pdf}

WRKSRC=			${WRKDIR}/epsg-v${VERS}sql-PostgreSQL
WRKSRC.pgsql=		${WRKDIR}/epsg-v${VERS}sql-PostgreSQL
WRKSRC.mysql=		${WRKDIR}/epsg-v${VERS}sql-mySQL

NO_BUILD=		yes

BINDIR=			${PREFIX}/bin
DOCDIR=			${PREFIX}/share/doc/epsg
EPSGDIR=		${PREFIX}/share/epsg

MESSAGE_SUBST+=		DOCDIR=${DOCDIR:Q}
MESSAGE_SUBST+=		EPSGDIR=${EPSGDIR:Q}

DATAFILES.pgsql+=	EPSG_v${VERS}.mdb_Data_PostgreSQL.sql
DATAFILES.pgsql+=	EPSG_v${VERS}.mdb_FKeys_PostgreSQL.sql
DATAFILES.pgsql+=	EPSG_v${VERS}.mdb_Tables_PostgreSQL.sql

DATAFILES.mysql+=	EPSG_v${VERS}.mdb_Data_MySQL.sql
DATAFILES.mysql+=	EPSG_v${VERS}.mdb_FKeys_MySQL.sql
DATAFILES.mysql+=	EPSG_v${VERS}.mdb_Tables_MySQL.sql

SUBST_STAGE.epsg=	configure
SUBST_FILES.epsg=	epsg-load
SUBST_SED.epsg=		-e "s:@PREFIX@:${PREFIX:Q}:"
SUBST_SED.epsg+=	-e "s:@EPSGDIR@:${EPSGDIR:Q}:"
SUBST_MESSAGE.epsg=	Fixing EPSG example script

PLIST_SUBST+=		VERS=${VERS}

post-extract:
	${CP} ${_DISTDIR}/G7-1.pdf ${WRKSRC}
	${CP} ${_DISTDIR}/G7-2.pdf ${WRKSRC}
	${CP} ${FILESDIR}/epsg-load ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EPSGDIR}
	${INSTALL_DATA} ${WRKSRC}/G7-1.pdf ${DOCDIR:Q}
	${INSTALL_DATA} ${WRKSRC}/G7-2.pdf ${DOCDIR:Q}
	${INSTALL_DATA} ${WRKSRC}/epsg-v${VERS}_Readme.pdf ${DOCDIR:Q}
	${INSTALL_SCRIPT} ${WRKSRC}/epsg-load ${BINDIR}
.for d in pgsql mysql
.for f in ${DATAFILES.${d}}
	${INSTALL_DATA} ${WRKSRC.${d}}/${f} ${EPSGDIR:Q}/${f}
.endfor
.endfor

.include "../../mk/bsd.pkg.mk"
