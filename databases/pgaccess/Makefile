# $NetBSD: Makefile,v 1.8 2001/02/16 14:17:36 wiz Exp $
#

DISTNAME=	pgaccess-0.98.6
WRKSRC=		${WRKDIR}/pgaccess
CATEGORIES=	databases
MASTER_SITES=	ftp://speedy.flex.ro/pub/pgaccess/ \
		ftp://ftp.flex.ro/pub/pgaccess/ \
		ftp://ftp.sai.msu.su/pub/unix/database/pgsql.app/ \
		ftp://crydee.sai.msu.ru/zeus/unix/database/pgsql.app/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.flex.ro/pgaccess/
COMMENT=	Free graphical database management tool for PostgreSQL

DEPENDS+=	tk-postgresql>=6.5.3:../../databases/tk-postgresql

NO_BUILD=	yes

.include "../../mk/bsd.prefs.mk"

PGUSER?=	pgsql

PGTKSH=		${PREFIX}/bin/pgtksh
PGACCESS_HOME=	${PREFIX}/share/pgaccess
HTMLDIR=	${PREFIX}/share/doc/html/pgaccess
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
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/main.tcl ${PGACCESS_HOME}
	${CP} -R ${WRKSRC}/lib ${PGACCESS_HOME}
	${CP} -R ${WRKSRC}/images ${PGACCESS_HOME}
	${CP} -R ${WRKSRC}/doc/html/* ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/demo/formdemo.sql ${EGDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PGACCESS_HOME} ${HTMLDIR} ${EGDIR}

.include "../../mk/bsd.pkg.mk"
