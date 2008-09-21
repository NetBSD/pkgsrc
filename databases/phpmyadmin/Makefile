# $NetBSD: Makefile,v 1.72.4.3 2008/09/21 13:18:54 rtr Exp $

DISTNAME=	phpMyAdmin-${DIST_VERSION}-all-languages
PKGNAME=	phpmyadmin-${DIST_VERSION:S/-//}
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=phpmyadmin/}
EXTRACT_SUFX=	.tar.bz2

OWNER=		tron@NetBSD.org
HOMEPAGE=	http://www.phpmyadmin.net/
COMMENT=	Set of PHP-scripts to adminstrate MySQL over the WWW

DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=4.3.3:../../misc/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-mysql{,i}>=4.3.3:../../databases/php-mysql

PKG_DESTDIR_SUPPORT=	user-destdir

FILES_SUBST+=	CONF_INC_PHP=${CONF_INC_PHP:Q} PMCONFFILE=${PMCONFFILE:Q}
PLIST_SUBST+=	DIST_VERSION=${DIST_VERSION:Q}
MESSAGE_SUBST+=	CONF_INC_PHP=${CONF_INC_PHP} PMCONFFILE=${PMCONFFILE:Q} \
		EXDIR=${EXDIR:Q}
USE_TOOLS+=	perl:run

CONF_INC_PHP=	${PREFIX}/share/phpmyadmin/config.inc.php
DIST_VERSION=	2.11.9.1
DOC_FILES=	CREDITS ChangeLog \
		Documentation.txt INSTALL LICENSE README \
		RELEASE-DATE-${DIST_VERSION} TODO

APACHE_USER?=	www
APACHE_GROUP?=	www
PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}
BUILD_DEFS+=	APACHE_USER APACHE_GROUP

PKG_USERS_VARS+=	APACHE_USER
PKG_GROUPS_VARS+=	APACHE_GROUP

EXDIR=		${PREFIX}/share/examples/phpmyadmin
PMCONFFILE=	${PKG_SYSCONFDIR}/config.inc.php
PMDIR=		${PREFIX}/share/phpmyadmin
REPLACE_PERL+=	scripts/convertcfg.pl

PKG_SYSCONFSUBDIR?=	phpmyadmin

NO_BUILD=		yes

INSTALL_DIRS=	js lang libraries libraries/auth libraries/dbg \
		libraries/dbi libraries/engines libraries/export \
		libraries/import libraries/tcpdf libraries/tcpdf/font \
		libraries/transformations pmd pmd/images pmd/scripts \
		pmd/styles pmd/styles/default pmd/styles/default/images \
		themes themes/darkblue_orange \
		themes/darkblue_orange/css themes/darkblue_orange/img \
		themes/original themes/original/css themes/original/img

do-configure:
	${SED} -e "s|@PMDIR@|${PMDIR}|g" ${FILESDIR}/phpmyadmin.conf	\
		>${WRKDIR}/phpmyadmin.conf

do-install:
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/phpmyadmin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/phpmyadmin
	${INSTALL_DATA_DIR} ${DESTDIR}${PMDIR}
	for dir in ${INSTALL_DIRS}; do \
		${INSTALL_DATA_DIR} ${DESTDIR}${PMDIR}/$$dir; \
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${PMDIR}/scripts

	${INSTALL_DATA} ${WRKSRC}/*.php ${DESTDIR}${PMDIR}
	${INSTALL_DATA} ${WRKSRC}/*.css ${DESTDIR}${PMDIR}
	${MV} ${DESTDIR}${PREFIX}/share/phpmyadmin/config.sample.inc.php \
	  ${DESTDIR}${EXDIR}/config.inc.php

	${INSTALL_DATA} ${WRKSRC}/Documentation.html ${DESTDIR}${PMDIR}
	${INSTALL_DATA} ${WRKSRC}/translators.html ${DESTDIR}${PMDIR}
	${INSTALL_DATA}	${WRKSRC}/ChangeLog ${DESTDIR}${PMDIR}

	for dir in ${INSTALL_DIRS}; do					\
		for file in ${WRKSRC}/$$dir/*; do			\
			case "$$file" in				\
			*.sh)						\
				;;					\
			*)						\
				if [ -f "$$file" ]; then		\
					${INSTALL_DATA} "$$file"	\
					  ${DESTDIR}${PMDIR}/$$dir;	\
				fi					\
				;;					\
			esac;						\
		done							\
	done

	${INSTALL_DATA} ${WRKSRC}/scripts/*.sql ${DESTDIR}${PMDIR}/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/convertcfg.pl \
	  ${DESTDIR}${PMDIR}/scripts

	cd ${WRKSRC} && \
	${INSTALL_DATA} ${DOC_FILES} ${DESTDIR}${PREFIX}/share/doc/phpmyadmin
	${INSTALL_DATA} ${WRKDIR}/phpmyadmin.conf ${DESTDIR}${EXDIR}/apache.conf

	${RM} -f ${DESTDIR}${PREFIX}/share/phpmyadmin/libraries/footer.inc.php.orig

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
