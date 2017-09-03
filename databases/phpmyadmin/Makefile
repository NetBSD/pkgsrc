# $NetBSD: Makefile,v 1.152 2017/09/03 08:53:06 wiz Exp $

DISTNAME=	phpMyAdmin-4.6.5.2-all-languages
PKGNAME=	${DISTNAME:S/-all-languages//:tl}
CATEGORIES=	databases www
MASTER_SITES=	https://files.phpmyadmin.net/phpMyAdmin/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.phpmyadmin.net/
COMMENT=	Set of PHP-scripts to adminstrate MySQL over the WWW
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-bz2>=5.3.0:../../archivers/php-bz2
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=5.3.0:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=5.3.0:../../archivers/php-zlib
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.3.0:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-gettext>=5.3.0:../../devel/php-gettext
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli>=5.3.0:../../databases/php-mysqli
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.3.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-mcrypt>=5.3.0:../../security/php-mcrypt
DEPENDS+=	${PHP_PKG_PREFIX}-json>=5.3.0:../../textproc/php-json

USE_TOOLS+=	pax

FILES_SUBST+=	APACHE_GROUP=${APACHE_GROUP} APACHE_USER=${APACHE_USER}
FILES_SUBST+=	PMSETUPDIR=${PMSETUPDIR} PMSETUPFILE=${PMSETUPFILE}
MESSAGE_SUBST+=	CONF_INC_PHP=${CONF_INC_PHP} PMCONFFILE=${PMCONFFILE}

CONF_INC_PHP=	${PREFIX}/share/phpmyadmin/config.inc.php
DOC_FILES=	CONTRIBUTING.md ChangeLog DCO LICENSE README \
		RELEASE-DATE-${PKGVERSION_NOREV}

.include "../../mk/bsd.prefs.mk"

APACHE_USER?=	www
APACHE_GROUP?=	www

PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}
BUILD_DEFS+=	APACHE_USER APACHE_GROUP VARBASE

PKG_USERS_VARS=		APACHE_USER
PKG_GROUPS_VARS=	APACHE_GROUP

EXDIR=		${PREFIX}/share/examples/phpmyadmin
PMCONFFILE=	${PKG_SYSCONFDIR}/config.inc.php
PMSETUPDIR=	${VARBASE}/phpmyadmin
PMSETUPFILE=	${PMSETUPDIR}/config.inc.php
PMDIR=		${PREFIX}/share/phpmyadmin

CONF_FILES+=	${EXDIR}/apache.conf ${PKG_SYSCONFDIR}/apache.conf

SRCS=		*.css *.ico *.php *.txt doc/html js libraries locale setup \
		sql templates test themes

PKG_SYSCONFSUBDIR=	phpmyadmin

NO_BUILD=		yes

CHECK_INTERPRETER_SKIP=	share/phpmyadmin/test/install-runkit

SUBST_CLASSES+=		paths
SUBST_FILES.paths+=	${WRKDIR}/phpmyadmin.conf
SUBST_FILES.paths+=	${WRKSRC}/libraries/vendor_config.php
SUBST_SED.paths+=	-e "s|@PMDIR@|${PMDIR}|g"
SUBST_SED.paths+=	-e 's|@@PMSETUPFILE@@|${PMSETUPFILE}|g'
SUBST_STAGE.paths=	post-configure

INSTALLATION_DIRS+=	${PREFIX}/share/doc/phpmyadmin \
			${PREFIX}/share/examples/phpmyadmin \
			${PMDIR}/doc ${PMDIR}/scripts

post-extract:
	${CP} ${FILESDIR}/phpmyadmin.conf ${WRKDIR}

do-configure:
	cd ${WRKSRC}/libraries; \
	${MV} ${WRKSRC}/config.sample.inc.php ${WRKDIR}/config.inc.php

pre-install:
	cd ${WRKSRC}; \
		${FIND} . -type f \( -name .buildinfo -o -name .jshintrc -o -name '*.orig' \) -exec ${RM} -f -- {} \;

do-install:
	cd ${WRKSRC} && pax -rw ${SRCS} ${DESTDIR}${PMDIR}
	${INSTALL_DATA} ${WRKDIR}/config.inc.php ${DESTDIR}${EXDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${DESTDIR}${EXDIR}
	${LN} -fs ${EXDIR} ${DESTDIR}${PREFIX}/share/phpmyadmin/examples
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${DOC_FILES} \
			${DESTDIR}${PREFIX}/share/doc/phpmyadmin
	${INSTALL_DATA} ${WRKDIR}/phpmyadmin.conf ${DESTDIR}${EXDIR}/apache.conf
	${LN} -fs ${PMCONFFILE} ${DESTDIR}${CONF_INC_PHP}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
