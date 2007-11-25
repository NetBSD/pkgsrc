# $NetBSD: Makefile,v 1.11 2007/11/25 17:53:23 adrianp Exp $
#

DISTNAME=	adodb496a
PKGNAME=	adodb-4.96a
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=adodb/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://adodb.sourceforge.net/
COMMENT=	Active Data Objects Data Base for php4

WRKSRC=			${WRKDIR}/adodb
NO_CONFIGURE=		YES
NO_BUILD=		YES

.include "../../lang/php/phpversion.mk"

.if ${PHP_PKG_PREFIX} == "php4"
.include "../../www/php4/buildlink3.mk"
.endif

.if ${PHP_PKG_PREFIX} == "php5"
.include "../../lang/php5/buildlink3.mk"
.endif

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

	${INSTALL_DATA} ${WRKSRC}/*.php ${PREFIX}/share/adodb
	${INSTALL_DATA} ${WRKSRC}/*.dtd ${PREFIX}/share/adodb
	${INSTALL_DATA} ${WRKSRC}/cute_icons_for_site/*.gif \
		${PREFIX}/share/adodb/cute_icons_for_site
	${INSTALL_DATA} ${WRKSRC}/datadict/*.php \
		${PREFIX}/share/adodb/datadict
	${INSTALL_DATA} ${WRKSRC}/drivers/*.php ${PREFIX}/share/adodb/drivers
	${INSTALL_DATA} ${WRKSRC}/lang/*.php ${PREFIX}/share/adodb/lang
	${INSTALL_DATA} ${WRKSRC}/perf/*.php ${PREFIX}/share/adodb/perf
	${INSTALL_DATA} ${WRKSRC}/tests/*.php ${PREFIX}/share/adodb/tests
	${INSTALL_DATA} ${WRKSRC}/tests/*.xml ${PREFIX}/share/adodb/tests
	${INSTALL_DATA} ${WRKSRC}/session/*.php ${PREFIX}/share/adodb/session
	${INSTALL_DATA} ${WRKSRC}/session/*.txt ${PREFIX}/share/adodb/session
	${INSTALL_DATA} ${WRKSRC}/session/*.sql ${PREFIX}/share/adodb/session
	${INSTALL_DATA} ${WRKSRC}/session/*.xml ${PREFIX}/share/adodb/session
	${INSTALL_DATA} ${WRKSRC}/xsl/*.xsl ${PREFIX}/share/adodb/xsl
	${INSTALL_DATA} ${WRKSRC}/docs/*.htm ${PREFIX}/share/doc/adodb
	${INSTALL_DATA} ${WRKSRC}/*.txt ${PREFIX}/share/doc/adodb

	${FIND} ${PREFIX}/share/adodb -name \*.\* -type f -print | \
		${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../mk/bsd.pkg.mk"
