# $NetBSD: Makefile,v 1.3 2000/04/27 08:24:17 rh Exp $
#

DISTNAME=	pgaccess-0.98.5
WRKSRC=		${WRKDIR}/pgaccess
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.flex.ro/pub/pgaccess/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.flex.ro/pgaccess/

DEPENDS+=	tk-postgresql-6.5.3:../../databases/postgresql

NO_BUILD=	yes

.include "../../mk/bsd.prefs.mk"

PGUSER?=	pgsql

PGTKSH=		${PREFIX}/bin/pgtksh
PGACCESS_HOME=	${PREFIX}/share/pgaccess
DOCDIR=		${PREFIX}/share/doc/pgaccess
EGDIR=		${PREFIX}/share/examples/pgaccess

pre-patch:
	${MV} ${WRKSRC}/pgaccess ${WRKSRC}/pgaccess.in

do-configure:
	${SED}	-e "s,@PGTKSH@,${PGTKSH},g" \
		-e "s,@PGACCESS_HOME@,${PGACCESS_HOME},g" \
		${WRKSRC}/pgaccess.in > ${WRKSRC}/pgaccess

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pgaccess ${PREFIX}/bin/pgaccess
	${INSTALL_DATA_DIR} ${PGACCESS_HOME}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/main.tcl ${PGACCESS_HOME}
	${CP} -R ${WRKSRC}/lib ${PGACCESS_HOME}
	${CP} -R ${WRKSRC}/images ${PGACCESS_HOME}
	${CP} -R ${WRKSRC}/doc/html/* ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/demo/formdemo.sql ${EGDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PGACCESS_HOME} ${DOCDIR} ${EGDIR}

.include "../../mk/bsd.pkg.mk"
