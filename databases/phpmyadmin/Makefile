# $NetBSD: Makefile,v 1.18 2004/10/31 23:47:32 jdolecek Exp $

DISTNAME=	phpMyAdmin-${DIST_VERSION}
PKGNAME=	phpmyadmin-${DIST_VERSION}
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=phpmyadmin/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/phpmyadmin/
COMMENT=	Set of PHP-scripts to adminstrate MySQL over the WWW

DEPENDS+=	php-mysql>=4.3.3:../../databases/php-mysql

PLIST_SUBST+=	CP="${CP}" DIST_VERSION=${DIST_VERSION} \
		PMCONFFILE=${PMCONFFILE} TEST="${TEST}"
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR} PMCONFFILE=${PMCONFFILE} \
		PMDIR=${PMDIR} EXDIR=${EXDIR}

CONF_INC_PHP=	${PREFIX}/share/phpmyadmin/config.inc.php
DIST_VERSION=	2.5.7-pl1
DOC_FILES=	CREDITS ChangeLog \
		Documentation.txt INSTALL LICENSE README \
		RELEASE-DATE-${DIST_VERSION} TODO

EXDIR=		${PREFIX}/share/examples/phpmyadmin
PMCONFFILE=	${PKG_SYSCONFDIR}/config.inc.php
PMDIR=		${PREFIX}/share/phpmyadmin
NO_BUILDLINK=	YES
CONF_FILES=	${EXDIR}/phpmyadmin.conf ${PKG_SYSCONFDIR}/phpmyadmin.conf

USE_PKGINSTALL=		YES
PKG_SYSCONFSUBDIR?=	phpmyadmin

SUBST_CLASSES=		paths
SUBST_STAGE.paths=	post-build
SUBST_FILES.paths=	${WRKDIR}/phpmyadmin.conf	
SUBST_SED.paths=	-e "s|@PMDIR@|${PMDIR}|g"
SUBST_MESSAGE.paths=	"Fixing paths."

do-build:
	@${CP} ${FILESDIR}/phpmyadmin.conf ${WRKDIR}/phpmyadmin.conf

do-install:
	#${INSTALL_DATA_DIR} ${PMCONFDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/phpmyadmin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/phpmyadmin
	${INSTALL_DATA_DIR} ${PMDIR}
	${INSTALL_DATA_DIR} ${PMDIR}/css
	${INSTALL_DATA_DIR} ${PMDIR}/images
	${INSTALL_DATA_DIR} ${PMDIR}/lang
	${INSTALL_DATA_DIR} ${PMDIR}/libraries
	${INSTALL_DATA_DIR} ${PMDIR}/libraries/auth
	${INSTALL_DATA_DIR} ${PMDIR}/libraries/dbg
	${INSTALL_DATA_DIR} ${PMDIR}/libraries/export
	${INSTALL_DATA_DIR} ${PMDIR}/libraries/fpdf
	${INSTALL_DATA_DIR} ${PMDIR}/libraries/fpdf/font
	${INSTALL_DATA_DIR} ${PMDIR}/libraries/transformations
	${INSTALL_DATA_DIR} ${PMDIR}/scripts

	${RM} -f ${CONF_INC_PHP}
	${INSTALL_SCRIPT} ${WRKSRC}/*.php ${PMDIR}
	${TEST} -f ${PMCONFFILE} || ${CP} -p ${CONF_INC_PHP} ${PMCONFFILE}
	${MV} ${CONF_INC_PHP} ${EXDIR}
	${LN} -s ${PMCONFFILE} ${CONF_INC_PHP}

	${INSTALL_DATA} ${WRKSRC}/Documentation.html ${PMDIR}
	${INSTALL_DATA} ${WRKSRC}/images/*.* ${PMDIR}/images
	${INSTALL_SCRIPT} ${WRKSRC}/lang/*.php ${PMDIR}/lang
	${INSTALL_SCRIPT} ${WRKSRC}/css/*.php ${PMDIR}/css

	${INSTALL_SCRIPT} ${WRKSRC}/libraries/*.* ${PMDIR}/libraries
	${INSTALL_SCRIPT} ${WRKSRC}/libraries/auth/*.php ${PMDIR}/libraries/auth
	${INSTALL_SCRIPT} ${WRKSRC}/libraries/dbg/*.php ${PMDIR}/libraries/dbg
	${INSTALL_SCRIPT} ${WRKSRC}/libraries/export/*.php \
		${PMDIR}/libraries/export
	${INSTALL_SCRIPT} ${WRKSRC}/libraries/fpdf/*.php ${PMDIR}/libraries/fpdf
	${INSTALL_SCRIPT} ${WRKSRC}/libraries/fpdf/font/*.php \
		${PMDIR}/libraries/fpdf/font
	${INSTALL_SCRIPT} ${WRKSRC}/libraries/transformations/*.php \
		${PMDIR}/libraries/transformations
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/*.* ${PMDIR}/scripts

	cd ${WRKSRC} && \
	${INSTALL_DATA} ${DOC_FILES} ${PREFIX}/share/doc/phpmyadmin
	${INSTALL_DATA} ${WRKDIR}/phpmyadmin.conf ${EXDIR}

.include "../../mk/bsd.pkg.mk"
