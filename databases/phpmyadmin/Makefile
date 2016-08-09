# $NetBSD: Makefile,v 1.148.2.1 2016/08/09 18:39:13 bsiegert Exp $

# When updating this package, please check there is no
# new INSTALL_DIRS to add. Remember pkg/51364 ;)

DISTNAME=	phpMyAdmin-${DIST_VERSION}-all-languages
PKGNAME=	phpmyadmin-${DIST_VERSION:S/-//}
CATEGORIES=	databases www
MASTER_SITES=	https://files.phpmyadmin.net/phpMyAdmin/${DIST_VERSION}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.phpmyadmin.net/
COMMENT=	Set of PHP-scripts to adminstrate MySQL over the WWW
LICENSE=	gnu-gpl-v2
PKGREVISION=	1

USE_TOOLS+=	pax bash
DEPENDS+=	${PHP_PKG_PREFIX}-bz2>=5.3.0:../../archivers/php-bz2
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=5.3.0:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=5.3.0:../../archivers/php-zlib
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.3.0:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-gettext>=5.3.0:../../devel/php-gettext
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli>=5.3.0:../../databases/php-mysqli
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.3.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-mcrypt>=5.3.0:../../security/php-mcrypt
DEPENDS+=	${PHP_PKG_PREFIX}-json>=5.3.0:../../textproc/php-json

FILES_SUBST+=	APACHE_GROUP=${APACHE_GROUP} APACHE_USER=${APACHE_USER}
FILES_SUBST+=	PMSETUPDIR=${PMSETUPDIR} PMSETUPFILE=${PMSETUPFILE}
PLIST_SUBST+=	DIST_VERSION=${DIST_VERSION:Q}
MESSAGE_SUBST+=	CONF_INC_PHP=${CONF_INC_PHP} PMCONFFILE=${PMCONFFILE:Q} \
		EXDIR=${EXDIR:Q}

CONF_INC_PHP=	${PREFIX}/share/phpmyadmin/config.inc.php
DIST_VERSION=	4.6.3
DOC_FILES=	ChangeLog LICENSE README RELEASE-DATE-${DIST_VERSION} \
		CONTRIBUTING.md DCO

APACHE_USER?=	www
APACHE_GROUP?=	www
PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}
BUILD_DEFS+=	APACHE_USER APACHE_GROUP

PKG_USERS_VARS+=	APACHE_USER
PKG_GROUPS_VARS+=	APACHE_GROUP

EXDIR=		${PREFIX}/share/examples/phpmyadmin
PMCONFFILE=	${PKG_SYSCONFDIR}/config.inc.php
PMSETUPDIR=	${VARBASE}/phpmyadmin
PMSETUPFILE=	${PMSETUPDIR}/config.inc.php
PMDIR=		${PREFIX}/share/phpmyadmin

PKG_SYSCONFSUBDIR?=	phpmyadmin

NO_BUILD=		yes

CHECK_INTERPRETER_SKIP+=	share/phpmyadmin/config.inc.php

INSTALLATION_DIRS+=	${PREFIX}/share/doc/phpmyadmin \
			${PREFIX}/share/examples/phpmyadmin \
			${PMDIR} ${PMDIR}/scripts

INSTALL_DIRS=	doc/html
INSTALL_DIRS+=	js
INSTALL_DIRS+=	libraries
INSTALL_DIRS+=	locale
INSTALL_DIRS+=	setup
INSTALL_DIRS+=	templates
INSTALL_DIRS+=	themes

.for dir in $(INSTALL_DIRS)
INSTALLATION_DIRS+=	${PMDIR}/${dir}
.endfor

REPLACE_INTERPRETER+=   bash
REPLACE.bash.old=       .*sh[^ ]*
REPLACE.bash.new=       ${TOOLS_PATH.bash}
REPLACE_FILES.bash=     ${WRKSRC}/libraries/plugins/transformations/*.sh

do-configure:
	${SED} -e "s|@PMDIR@|${PMDIR}|g" ${FILESDIR}/phpmyadmin.conf	\
	  >${WRKDIR}/phpmyadmin.conf
	cd ${WRKSRC}/libraries; 					\
	${SED} -e "s#@@PMSETUPFILE@@#${PMSETUPFILE}#" vendor_config.php	\
	  >vendor_config.php.pkgsrc

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.css ${DESTDIR}${PMDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ico ${DESTDIR}${PMDIR}
	${INSTALL_DATA} ${WRKSRC}/*.php ${DESTDIR}${PMDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DESTDIR}${PMDIR}

	${MV} ${DESTDIR}${PREFIX}/share/phpmyadmin/config.sample.inc.php \
	  ${DESTDIR}${EXDIR}/config.inc.php
	${INSTALL_DATA} ${WRKSRC}/examples/* ${DESTDIR}${EXDIR}
	${LN} -fs ${EXDIR} ${DESTDIR}${PREFIX}/share/phpmyadmin/examples
	${RM} -f ${WRKSRC}/libraries/vendor_config.php.orig

	for dir in ${INSTALL_DIRS}; do						\
		cd ${WRKSRC}/$$dir &&						\
		pax -rw -pmp . ${DESTDIR}${PMDIR}/$$dir;			\
	done

	cd ${WRKSRC} && \
	${INSTALL_DATA} ${DOC_FILES} ${DESTDIR}${PREFIX}/share/doc/phpmyadmin
	${INSTALL_DATA} ${WRKDIR}/phpmyadmin.conf ${DESTDIR}${EXDIR}/apache.conf
	${LN} -s ${PMCONFFILE} ${DESTDIR}${CONF_INC_PHP}
	cd ${DESTDIR}${PREFIX}/share/phpmyadmin/libraries; \
	${MV} -f vendor_config.php.pkgsrc vendor_config.php

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
