# $NetBSD: Makefile,v 1.9 2001/05/22 04:23:50 jlam Exp $
#

DISTNAME=	pgaccess-0.98.7
WRKSRC=		${WRKDIR}/pgaccess
CATEGORIES=	databases
MASTER_SITES=	http://www.flex.ro/pgaccess/download/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.flex.ro/pgaccess/
COMMENT=	Free graphical database management tool for PostgreSQL

DEPENDS+=	tk-postgresql>=6.5.3:../../databases/tk-postgresql

NO_BUILD=	# defined

.include "../../mk/bsd.prefs.mk"

PGTKSH=		${PREFIX}/bin/pgtksh
PGACCESS_HOME=	${PREFIX}/share/pgaccess
HTMLDIR=	${PREFIX}/share/doc/html/pgaccess
EGDIR=		${PREFIX}/share/examples/pgaccess

post-extract:
	cd ${WRKSRC}; ${MV} -f pgaccess pgaccess.in

do-configure:
	${SED}	-e "s|@PGTKSH@|${PGTKSH}|g"				\
		-e "s|@PGACCESS_HOME@|${PGACCESS_HOME}|g"		\
		${WRKSRC}/pgaccess.in > ${WRKSRC}/pgaccess

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pgaccess ${PREFIX}/bin/pgaccess
	${INSTALL_DATA_DIR} ${PGACCESS_HOME} ${HTMLDIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/main.tcl ${PGACCESS_HOME}
	${CP} -R ${WRKSRC}/lib ${PGACCESS_HOME}
	${CP} -R ${WRKSRC}/images ${PGACCESS_HOME}
	${CP} -R ${WRKSRC}/doc/html/* ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/demo/formdemo.sql ${EGDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PGACCESS_HOME} ${HTMLDIR} ${EGDIR}

.include "../../mk/bsd.pkg.mk"
