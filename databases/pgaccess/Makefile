# $NetBSD: Makefile,v 1.14 2004/04/24 22:46:09 jlam Exp $
#

DISTNAME=	pgaccess-0.98.8
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.pgaccess.org/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.pgaccess.org/
COMMENT=	Graphical database management tool for PostgreSQL

DEPENDS+=	tk-postgresql>=7.2.1:../../databases/tk-postgresql

NO_BUILD=	# defined

.include "../../mk/bsd.prefs.mk"

PGTKSH=		${PREFIX}/bin/pgtksh
PGACCESS_HOME=	${PREFIX}/share/pgaccess
HTMLDIR=	${PREFIX}/share/doc/html/pgaccess
EGDIR=		${PREFIX}/share/examples/pgaccess

do-configure:
	for file in ${WRKSRC}/pgaccess.tcl; do				\
		${SED}	-e "s|@PGTKSH@|${PGTKSH}|g"			\
			-e "s|@PGACCESS_HOME@|${PGACCESS_HOME}|g"	\
			$$file > $$file.new;				\
		${MV} -f $$file.new $$file;				\
	done

do-install:
	${INSTALL_DATA_DIR} ${PGACCESS_HOME}
	${INSTALL_SCRIPT} ${WRKSRC}/pgaccess.tcl ${PGACCESS_HOME}
	${LN} -sf ${PGACCESS_HOME}/pgaccess.tcl ${PREFIX}/bin/pgaccess
	${CP} -R ${WRKSRC}/images ${PGACCESS_HOME}
	${CP} -R ${WRKSRC}/lib ${PGACCESS_HOME}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${CP} -R ${WRKSRC}/doc/html/* ${HTMLDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	for file in ${WRKSRC}/demo/*; do				\
		${INSTALL_DATA} $$file ${EGDIR};			\
	done
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PGACCESS_HOME} ${HTMLDIR} ${EGDIR}

.include "../../mk/bsd.pkg.mk"
