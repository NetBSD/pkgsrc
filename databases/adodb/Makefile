# $NetBSD: Makefile,v 1.5 2006/01/24 13:37:45 adrianp Exp $
#

DISTNAME=	adodb471
PKGNAME=	adodb-4.71
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=adodb/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE= 	http://adodb.sourceforge.net/
COMMENT=	Active Data Objects Data Base for php4

DEPENDS+=	php>=4.1.0:../../www/php4

WRKSRC=		${WRKDIR}/adodb
NO_CONFIGURE=	YES
NO_BUILD=	YES

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/adodb
	${INSTALL_DATA_DIR} ${PREFIX}/share/adodb/cute_icons_for_site
	${INSTALL_DATA_DIR} ${PREFIX}/share/adodb/datadict
	${INSTALL_DATA_DIR} ${PREFIX}/share/adodb/drivers
	${INSTALL_DATA_DIR} ${PREFIX}/share/adodb/lang
	${INSTALL_DATA_DIR} ${PREFIX}/share/adodb/perf
	${INSTALL_DATA_DIR} ${PREFIX}/share/adodb/tests
	${INSTALL_DATA_DIR} ${PREFIX}/share/adodb/xsl
	${INSTALL_DATA_DIR} ${PREFIX}/share/adodb/session
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/adodb
	${INSTALL_SCRIPT} ${WRKSRC}/*.php ${PREFIX}/share/adodb
	${INSTALL_SCRIPT} ${WRKSRC}/*.dtd ${PREFIX}/share/adodb
	${INSTALL_DATA} ${WRKSRC}/cute_icons_for_site/*.gif \
		${PREFIX}/share/adodb/cute_icons_for_site
	${INSTALL_SCRIPT} ${WRKSRC}/datadict/*.php \
		${PREFIX}/share/adodb/datadict
	${INSTALL_SCRIPT} ${WRKSRC}/drivers/*.php ${PREFIX}/share/adodb/drivers
	${INSTALL_SCRIPT} ${WRKSRC}/lang/*.php ${PREFIX}/share/adodb/lang
	${INSTALL_SCRIPT} ${WRKSRC}/perf/*.php ${PREFIX}/share/adodb/perf
	${INSTALL_SCRIPT} ${WRKSRC}/tests/*.php ${PREFIX}/share/adodb/tests
	${INSTALL_SCRIPT} ${WRKSRC}/tests/*.xml ${PREFIX}/share/adodb/tests
	${INSTALL_SCRIPT} ${WRKSRC}/session/*.php ${PREFIX}/share/adodb/session
	${INSTALL_SCRIPT} ${WRKSRC}/session/*.txt ${PREFIX}/share/adodb/session
	${INSTALL_SCRIPT} ${WRKSRC}/session/*.sql ${PREFIX}/share/adodb/session
	${INSTALL_SCRIPT} ${WRKSRC}/xsl/*.xsl ${PREFIX}/share/adodb/xsl
	${INSTALL_DATA} ${WRKSRC}/docs/*.htm ${PREFIX}/share/doc/adodb
	${INSTALL_DATA} ${WRKSRC}/*.txt ${PREFIX}/share/doc/adodb

.include "../../mk/bsd.pkg.mk"
