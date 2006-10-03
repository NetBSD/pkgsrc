# $NetBSD: Makefile,v 1.3 2006/10/03 12:53:44 gdt Exp $
#

DISTNAME=		epsg-v6_11sql-PostgreSQL
PKGNAME=		epsg-6.11
PKGREVISION=		1
CATEGORIES=		geography databases
MASTER_SITES+=		http://www.epsg.org/databases/
DISTFILES+=		epsg-v6_11sql-PostgreSQL.zip \
			epsg-v6_11sql-mySQL.zip \
			G7-1.pdf G7-2.pdf
EXTRACT_ONLY=		epsg-v6_11sql-PostgreSQL.zip \
			epsg-v6_11sql-mySQL.zip
DIST_SUBDIR=		epsg-20060823

MAINTAINER=		brook@nmsu.edu
HOMEPAGE=		http://www.epsg.org/
COMMENT=		EPSG Geodetic Parameters database

LICENSE=		epsg-license
RESTRICTED=		No commercial redistribution
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

SITES.G7-1.pdf=		http://www.epsg.org/guides/docs/
SITES.G7-2.pdf=		${SITES.G7-1.pdf}

WRKSRC=			${WRKDIR}/epsg-v6_11sql-postgresql
WRKSRC.pgsql=		${WRKDIR}/epsg-v6_11sql-PostgreSQL
WRKSRC.mysql=		${WRKDIR}/epsg-v6_11sql-mySQL

NO_BUILD=		yes

DOCDIR=			${PREFIX}/share/doc/epsg
EGDIR=			${PREFIX}/share/examples/epsg
EPSGDIR=		${PREFIX}/share/epsg

MESSAGE_SUBST+=		DOCDIR=${DOCDIR:Q}
MESSAGE_SUBST+=		EGDIR=${EGDIR:Q}
MESSAGE_SUBST+=		EPSGDIR=${EPSGDIR:Q}

DATAFILES.pgsql+=	EPSG_v6_11.mdb_Data_PostgreSQL.sql
DATAFILES.pgsql+=	EPSG_v6_11.mdb_FKeys_PostgreSQL.sql
DATAFILES.pgsql+=	EPSG_v6_11.mdb_Tables_PostgreSQL.sql

DATAFILES.mysql+=	EPSG_v6_11.mdb_Data_MySQL.sql
DATAFILES.mysql+=	EPSG_v6_11.mdb_FKeys_MySQL.sql
DATAFILES.mysql+=	EPSG_v6_11.mdb_Tables_MySQL.sql

SUBST_CLASSES+=		epsg
SUBST_STAGE.epsg=	configure
SUBST_FILES.epsg=	epsg.sh
SUBST_SED.epsg=		-e "s:$$[{]PREFIX[}]:${PREFIX:Q}:"
SUBST_SED.epsg+=	-e "s:$$[{]EPSGDIR[}]:${EPSGDIR:Q}:"
SUBST_MESSAGE.epsg=	Fixing EPSG example script

post-extract:
	${CP} ${_DISTDIR}/G7-1.pdf ${WRKSRC}
	${CP} ${_DISTDIR}/G7-2.pdf ${WRKSRC}
	${CP} ${FILESDIR}/epsg.sh ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${EPSGDIR}
	${INSTALL_DATA} ${WRKSRC}/G7-1.pdf ${DOCDIR:Q}
	${INSTALL_DATA} ${WRKSRC}/G7-2.pdf ${DOCDIR:Q}
	${INSTALL_DATA} ${WRKSRC}/epsg-v6_11-readme.pdf ${DOCDIR:Q}
	${INSTALL_SCRIPT} ${WRKSRC}/epsg.sh ${EGDIR}/epsg
.for d in pgsql mysql
.for f in ${DATAFILES.${d}}
	${INSTALL_DATA} ${WRKSRC.${d}}/${f} ${EPSGDIR:Q}/${f}
.endfor
.endfor

.include "../../mk/bsd.pkg.mk"
