# $NetBSD: Makefile,v 1.16 2004/04/25 01:14:25 xtraeme Exp $

DISTNAME=	phpMyAdmin-${DIST_VERSION}-php
PKGNAME=	phpmyadmin-2.5.3rc3
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=phpmyadmin/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/phpmyadmin/
COMMENT=	Set of PHP-scripts to adminstrate MySQL over the WWW

DEPENDS+=	php-mysql>=4.3.3:../../databases/php4-mysql

PLIST_SUBST+=	CP="${CP}" DIST_VERSION=${DIST_VERSION} \
		PMCONFFILE=${PMCONFFILE} TEST="${TEST}"
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR} PMCONFFILE=${PMCONFFILE} \
		PMDIR=${PMDIR} EXDIR=${EXDIR}

WRKSRC=		${WRKDIR}/${DISTNAME:S/-php//}
CONF_INC_PHP=	${PREFIX}/share/phpmyadmin/config.inc.php
DIST_VERSION=	2.5.3-rc3
DOC_FILES=	ANNOUNCE.txt CREDITS ChangeLog \
		Documentation.txt INSTALL LICENSE README \
		RELEASE-DATE-${DIST_VERSION} TODO
EXDIR=		${PREFIX}/share/examples/phpmyadmin
PMCONFDIR=	${PKG_SYSCONFDIR}/phpmyadmin
PMCONFFILE=	${PMCONFDIR}/config.inc.php
PMDIR=		${PREFIX}/share/phpmyadmin
NO_BUILDLINK=	yes

do-build:
	@${SED} -e 's#@PMDIR@#${PMDIR}#g' ${FILESDIR}/phpmyadmin.conf \
	  >${WRKDIR}/phpmyadmin.conf

do-install:
	${INSTALL_DATA_DIR} ${PMCONFDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/phpmyadmin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/phpmyadmin
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpmyadmin
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpmyadmin/images
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpmyadmin/lang
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpmyadmin/libraries
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpmyadmin/libraries/auth
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpmyadmin/libraries/dbg
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpmyadmin/libraries/export
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpmyadmin/libraries/fpdf
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpmyadmin/libraries/fpdf/font
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpmyadmin/libraries/transformations
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpmyadmin/scripts
	${RM} -f ${CONF_INC_PHP}
	${INSTALL_SCRIPT} ${WRKSRC}/*.php ${PREFIX}/share/phpmyadmin
	${TEST} -f ${PMCONFFILE} || ${CP} -p ${CONF_INC_PHP} ${PMCONFFILE}
	${MV} ${CONF_INC_PHP} ${EXDIR}
	${LN} -s ${PMCONFFILE} ${CONF_INC_PHP}
	${INSTALL_DATA} ${WRKSRC}/Documentation.html ${PREFIX}/share/phpmyadmin
	${INSTALL_DATA} ${WRKSRC}/badwords.txt ${PREFIX}/share/phpmyadmin
	${INSTALL_DATA} ${WRKSRC}/images/*.* ${PREFIX}/share/phpmyadmin/images
	${INSTALL_SCRIPT} ${WRKSRC}/lang/*.php ${PREFIX}/share/phpmyadmin/lang
	${INSTALL_SCRIPT} ${WRKSRC}/libraries/*.* ${PREFIX}/share/phpmyadmin/libraries
	${INSTALL_SCRIPT} ${WRKSRC}/libraries/auth/*.php ${PREFIX}/share/phpmyadmin/libraries/auth
	${INSTALL_SCRIPT} ${WRKSRC}/libraries/dbg/*.php ${PREFIX}/share/phpmyadmin/libraries/dbg
	${INSTALL_SCRIPT} ${WRKSRC}/libraries/export/*.php ${PREFIX}/share/phpmyadmin/libraries/export
	${INSTALL_SCRIPT} ${WRKSRC}/libraries/fpdf/*.php ${PREFIX}/share/phpmyadmin/libraries/fpdf
	${INSTALL_SCRIPT} ${WRKSRC}/libraries/fpdf/font/*.php ${PREFIX}/share/phpmyadmin/libraries/fpdf/font
	${INSTALL_SCRIPT} ${WRKSRC}/libraries/transformations/*.php ${PREFIX}/share/phpmyadmin/libraries/transformations
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/*.* ${PREFIX}/share/phpmyadmin/scripts
	cd ${WRKSRC}; \
	${INSTALL_DATA} ${DOC_FILES} ${PREFIX}/share/doc/phpmyadmin
	${INSTALL_DATA} ${WRKDIR}/phpmyadmin.conf ${EXDIR}

.include "../../mk/bsd.pkg.mk"
