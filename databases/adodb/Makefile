# $NetBSD: Makefile,v 1.1.1.1 2004/04/20 09:49:33 xtraeme Exp $
#

DISTNAME=	adodb400
PKGNAME=	adodb-4.00
CATEGORIES=	databases www
MASTER_SITES=	http://phplens.com/lens/dl/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://php.weblogs.com/ADODB
COMMENT=	Active Data Objects Data Base for php4

DEPENDS+=       php>=4.0.5:../../www/php4

WRKSRC=		${WRKDIR}/adodb
NO_CONFIGURE=	YES
NO_BUILD=	YES
NO_BUILDLINK=	YES

DOC_FILES=	license.txt readme.htm readme.txt tips_portable_sql.htm \
		tute.htm docs-datadict.htm old-changelog.htm docs-adodb.htm \
		docs-session.htm docs-perf.htm

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/adodb
	${INSTALL_DATA_DIR} ${PREFIX}/share/adodb/cute_icons_for_site
	${INSTALL_DATA_DIR} ${PREFIX}/share/adodb/datadict
	${INSTALL_DATA_DIR} ${PREFIX}/share/adodb/drivers
	${INSTALL_DATA_DIR} ${PREFIX}/share/adodb/lang
	${INSTALL_DATA_DIR} ${PREFIX}/share/adodb/perf
	${INSTALL_DATA_DIR} ${PREFIX}/share/adodb/tests
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/adodb
	${INSTALL_SCRIPT} ${WRKSRC}/*.php ${PREFIX}/share/adodb
	${INSTALL_DATA} ${WRKSRC}/cute_icons_for_site/*.png \
		${PREFIX}/share/adodb/cute_icons_for_site
	${INSTALL_DATA} ${WRKSRC}/cute_icons_for_site/*.gif \
		${PREFIX}/share/adodb/cute_icons_for_site
	${INSTALL_SCRIPT} ${WRKSRC}/datadict/*.php \
		${PREFIX}/share/adodb/datadict
	${INSTALL_SCRIPT} ${WRKSRC}/drivers/*.php ${PREFIX}/share/adodb/drivers
	${INSTALL_SCRIPT} ${WRKSRC}/lang/*.php ${PREFIX}/share/adodb/lang
	${INSTALL_SCRIPT} ${WRKSRC}/perf/*.php ${PREFIX}/share/adodb/perf
	${INSTALL_SCRIPT} ${WRKSRC}/tests/*.php ${PREFIX}/share/adodb/tests
	${INSTALL_SCRIPT} ${WRKSRC}/tests/*.xml ${PREFIX}/share/adodb/tests
	for FILE in ${DOC_FILES}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$FILE ${PREFIX}/share/doc/adodb; \
	done

.include "../../mk/bsd.pkg.mk"
