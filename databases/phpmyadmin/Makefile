# $NetBSD: Makefile,v 1.52.2.3 2006/11/23 08:52:58 ghen Exp $

DISTNAME=	phpMyAdmin-${DIST_VERSION}-all-languages
PKGNAME=	phpmyadmin-${DIST_VERSION:S/-//}
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=phpmyadmin/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.phpmyadmin.net/
COMMENT=	Set of PHP-scripts to adminstrate MySQL over the WWW

DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=4.3.3:../../misc/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-mysql{,i}>=4.3.3:../../databases/php-mysql

PLIST_SUBST+=	CP=${CP:Q} DIST_VERSION=${DIST_VERSION:Q} \
		PMCONFFILE=${PMCONFFILE:Q} TEST=${TEST:Q}
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q} \
		PMCONFFILE=${PMCONFFILE:Q} PMDIR=${PMDIR:Q} \
		EXDIR=${EXDIR:Q}

CONF_INC_PHP=	${PREFIX}/share/phpmyadmin/config.inc.php
DIST_VERSION=	2.9.1.1
DOC_FILES=	CREDITS ChangeLog \
		Documentation.txt INSTALL LICENSE README \
		RELEASE-DATE-${DIST_VERSION} TODO

APACHE_USER?=	www
EXDIR=		${PREFIX}/share/examples/phpmyadmin
PMCONFFILE=	${PKG_SYSCONFDIR}/config.inc.php
PMDIR=		${PREFIX}/share/phpmyadmin
CONF_FILES=	${EXDIR}/config.inc.php ${PKG_SYSCONFDIR}/config.inc.php
SPECIAL_PERMS=	${PKG_SYSCONFDIR}/config.inc.php ${APACHE_USER} wheel 0600
BUILD_DEFS+=	APACHE_USER

PKG_SYSCONFSUBDIR?=	phpmyadmin

NO_BUILD=		yes

INSTALL_DIRS=	css js lang libraries libraries/auth libraries/dbg \
		libraries/dbi libraries/engines libraries/export \
		libraries/fpdf libraries/fpdf/font libraries/import \
		libraries/transformations themes themes/darkblue_orange \
		themes/darkblue_orange/css themes/darkblue_orange/img \
		themes/original themes/original/css themes/original/img

do-configure:
	${SED} -e "s|@PMDIR@|${PMDIR}|g" ${FILESDIR}/phpmyadmin.conf	\
		>${WRKDIR}/phpmyadmin.conf

do-install:
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/phpmyadmin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/phpmyadmin
	${INSTALL_DATA_DIR} ${PMDIR}
	for dir in ${INSTALL_DIRS}; do \
		${INSTALL_DATA_DIR} ${PMDIR}/$$dir; \
	done
	${INSTALL_DATA_DIR} ${PMDIR}/scripts

	${RM} -f ${CONF_INC_PHP}	# just in case
	${LN} -s ${PMCONFFILE} ${CONF_INC_PHP}
	${INSTALL_DATA} ${WRKSRC}/*.php ${PMDIR}
	${INSTALL_DATA} ${WRKSRC}/*.css ${PMDIR}

	${INSTALL_DATA} ${WRKSRC}/Documentation.html ${PMDIR}
	${INSTALL_DATA} ${WRKSRC}/translators.html ${PMDIR}
	${INSTALL_DATA}	${WRKSRC}/ChangeLog ${PMDIR}

	for dir in ${INSTALL_DIRS}; do					\
		for file in "${WRKSRC}/$$dir"/*; do			\
			${TEST} -f "$$file" -a `${BASENAME} "$$file" .sh` = `${BASENAME} "$$file"` &&				\
			${INSTALL_DATA} $$file ${PMDIR}/$$dir;		\
		done							\
	done

	${INSTALL_DATA} ${WRKSRC}/scripts/*.sql ${PMDIR}/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/convertcfg.pl ${PMDIR}/scripts

	cd ${WRKSRC} && \
	${INSTALL_DATA} ${DOC_FILES} ${PREFIX}/share/doc/phpmyadmin
	${INSTALL_DATA} ${WRKDIR}/phpmyadmin.conf ${EXDIR}/apache.conf

	${RM} -f ${PREFIX}/share/phpmyadmin/libraries/footer.inc.php.orig

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
