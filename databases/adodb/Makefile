# $NetBSD: Makefile,v 1.14 2010/02/18 13:45:35 joerg Exp $
#

DISTNAME=	adodb496a
PKGNAME=	adodb-4.96a
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=adodb/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://adodb.sourceforge.net/
COMMENT=	Active Data Objects Data Base for php4

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/adodb
NO_CONFIGURE=		YES
NO_BUILD=		YES

.include "../../lang/php/phpversion.mk"

.if ${PHP_PKG_PREFIX} == "php5"
.include "../../lang/php5/buildlink3.mk"
.endif

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/adodb
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/adodb/cute_icons_for_site
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/adodb/datadict
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/adodb/drivers
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/adodb/lang
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/adodb/perf
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/adodb/tests
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/adodb/xsl
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/adodb/session
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/adodb

	${INSTALL_DATA} ${WRKSRC}/*.php ${DESTDIR}${PREFIX}/share/adodb
	${INSTALL_DATA} ${WRKSRC}/*.dtd ${DESTDIR}${PREFIX}/share/adodb
	${INSTALL_DATA} ${WRKSRC}/cute_icons_for_site/*.gif \
		${DESTDIR}${PREFIX}/share/adodb/cute_icons_for_site
	${INSTALL_DATA} ${WRKSRC}/datadict/*.php \
		${DESTDIR}${PREFIX}/share/adodb/datadict
	${INSTALL_DATA} ${WRKSRC}/drivers/*.php \
		${DESTDIR}${PREFIX}/share/adodb/drivers
	${INSTALL_DATA} ${WRKSRC}/lang/*.php \
		${DESTDIR}${PREFIX}/share/adodb/lang
	${INSTALL_DATA} ${WRKSRC}/perf/*.php \
		${DESTDIR}${PREFIX}/share/adodb/perf
	${INSTALL_DATA} ${WRKSRC}/tests/*.php \
		${DESTDIR}${PREFIX}/share/adodb/tests
	${INSTALL_DATA} ${WRKSRC}/tests/*.xml \
		${DESTDIR}${PREFIX}/share/adodb/tests
	${INSTALL_DATA} ${WRKSRC}/session/*.php \
		${DESTDIR}${PREFIX}/share/adodb/session
	${INSTALL_DATA} ${WRKSRC}/session/*.txt \
		${DESTDIR}${PREFIX}/share/adodb/session
	${INSTALL_DATA} ${WRKSRC}/session/*.sql \
		${DESTDIR}${PREFIX}/share/adodb/session
	${INSTALL_DATA} ${WRKSRC}/session/*.xml \
		${DESTDIR}${PREFIX}/share/adodb/session
	${INSTALL_DATA} ${WRKSRC}/xsl/*.xsl ${DESTDIR}${PREFIX}/share/adodb/xsl
	${INSTALL_DATA} ${WRKSRC}/docs/*.htm ${DESTDIR}${PREFIX}/share/doc/adodb
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DESTDIR}${PREFIX}/share/doc/adodb

	${FIND} ${DESTDIR}${PREFIX}/share/adodb -name \*.\* -type f -print | \
		${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../mk/bsd.pkg.mk"
