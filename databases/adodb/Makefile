# $NetBSD: Makefile,v 1.24 2025/06/15 15:54:44 taca Exp $
#

DISTNAME=	adodb-${VERS}
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_GITHUB:=ADOdb/}
GITHUB_PROJECT=	ADOdb
GITHUB_TAG=	v${VERS}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ADOdb/ADOdb
COMMENT=	Active Data Objects Data Base for php

VERS=		5.22.9

WRKSRC=			${WRKDIR}/ADOdb-${VERS}
NO_CONFIGURE=		YES
NO_BUILD=		YES

#INSTLATTION_DIRS+=

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/adodb
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/adodb/datadict
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/adodb/drivers
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/adodb/lang
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/adodb/perf
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/adodb/xsl
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/adodb/session
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/adodb

	${INSTALL_DATA} ${WRKSRC}/*.php ${DESTDIR}${PREFIX}/share/adodb
	${INSTALL_DATA} ${WRKSRC}/*.dtd ${DESTDIR}${PREFIX}/share/adodb
#	${INSTALL_DATA} ${WRKSRC}/cute_icons_for_site/*.gif \
#		${DESTDIR}${PREFIX}/share/adodb/cute_icons_for_site
	${INSTALL_DATA} ${WRKSRC}/datadict/*.php \
		${DESTDIR}${PREFIX}/share/adodb/datadict
	${INSTALL_DATA} ${WRKSRC}/drivers/*.php \
		${DESTDIR}${PREFIX}/share/adodb/drivers
	${INSTALL_DATA} ${WRKSRC}/lang/*.php \
		${DESTDIR}${PREFIX}/share/adodb/lang
	${INSTALL_DATA} ${WRKSRC}/perf/*.php \
		${DESTDIR}${PREFIX}/share/adodb/perf
	${INSTALL_DATA} ${WRKSRC}/session/*.php \
		${DESTDIR}${PREFIX}/share/adodb/session
	${INSTALL_DATA} ${WRKSRC}/session/*.txt \
		${DESTDIR}${PREFIX}/share/adodb/session
	${INSTALL_DATA} ${WRKSRC}/session/*.sql \
		${DESTDIR}${PREFIX}/share/adodb/session
	${INSTALL_DATA} ${WRKSRC}/session/*.xml \
		${DESTDIR}${PREFIX}/share/adodb/session
	${INSTALL_DATA} ${WRKSRC}/xsl/*.xsl ${DESTDIR}${PREFIX}/share/adodb/xsl
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DESTDIR}${PREFIX}/share/doc/adodb

	${FIND} ${DESTDIR}${PREFIX}/share/adodb -name \*.\* -type f -print | \
		${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
