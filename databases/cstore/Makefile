# $NetBSD: Makefile,v 1.5 2008/05/25 21:42:20 joerg Exp $

DISTNAME=	cstore0.2
PKGNAME=	cstore-0.2
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://db.lcs.mit.edu/projects/cstore/
MASTER_SITES+=	http://db.csail.mit.edu/data/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} data4.tar.gz D6.data.ros.gz

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://db.lcs.mit.edu/projects/cstore/
COMMENT=	Read-optimised column store relational DBMS

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake perl pax
USE_LANGUAGES+=	c c++
WRKSRC=		${WRKDIR}/cstore

REPLACE_PERL=	Build/BSsrcs

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	Build/makefile.init
SUBST_SED.prefix+=	-e 's|@PREFIX@|'${PREFIX:Q}'|g'

DATAFILES=	D1.data.mini
DATAFILES+=	D1.data.retsupp50sort
DATAFILES+=	D1.shipdate.mini
DATAFILES+=	D1.suppkey.mini
DATAFILES+=	D10.data.ros
DATAFILES+=	D10.data.wos
DATAFILES+=	D2.data
DATAFILES+=	D2.data.mini
DATAFILES+=	D3.custkey.mini
DATAFILES+=	D3.data.mini
DATAFILES+=	D4.data
DATAFILES+=	D4.data.mini
DATAFILES+=	D5.data.mini
DATAFILES+=	D6.data.ros
DATAFILES+=	D6.data.wos
DATAFILES+=	D7.data.ros
DATAFILES+=	D7.data.wos
DATAFILES+=	D8.data.ros
DATAFILES+=	D8.data.wos
DATAFILES+=	D9.data.ros
DATAFILES+=	D9.data.wos
DATAFILES+=	d1.lsuppkey.full
DATAFILES+=	deltaPos.test
DATAFILES+=	deltaPosTestBig2
DATAFILES+=	lineitem.sorted.full
DATAFILES+=	lshipdate.sorted.mini
DATAFILES+=	lshipdate.sorted.tiny
DATAFILES+=	supp.data

AUTO_MKDIRS=			yes

post-extract:
	cd ${WRKDIR} && mv ${DATAFILES} ${WRKSRC}/data

do-build:
	cd ${WRKSRC}/src && ${SETENV} ${BUILD_ENV} ${MAKE} debug2
	cd ${WRKSRC}/src &&  ./cstoreqptest 0 createData.cnf global.cnf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/cstoreqptest \
		${DESTDIR}${PREFIX}/bin/cstoreqp
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/cstore/data
	cd ${WRKSRC}/data && pax -rwpe . ${DESTDIR}${PREFIX}/cstore/data
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/cstore
	cd ${WRKSRC}/doc && pax -rwpe . ${DESTDIR}${PREFIX}/share/doc/cstore

.include "../../archivers/lzo/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
