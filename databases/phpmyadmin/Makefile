# $NetBSD: Makefile,v 1.159 2019/06/16 09:13:11 tm Exp $

DISTNAME=	phpMyAdmin-4.9.0.1-all-languages
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME:S/-all-languages//:tl}
CATEGORIES=	databases www
MASTER_SITES=	https://files.phpmyadmin.net/phpMyAdmin/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	tm@NetBSD.org
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
DEPENDS+=	${PHP_PKG_PREFIX}-json>=5.3.0:../../textproc/php-json

.include "../../lang/php/phpversion.mk"

.if ${PKG_PHP_VERSION} < 71
DEPENDS+=	${PHP_PKG_PREFIX}-mcrypt>=5.3.0:../../security/php-mcrypt
.else
DEPENDS+=	${PHP_PKG_PREFIX}-pecl-mcrypt>=1.0.1:../../security/php-pecl-mcrypt
.endif

USE_TOOLS+=	pax

APACHE_USER?=	www
APACHE_GROUP?=	www

PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}
BUILD_DEFS+=	APACHE_USER APACHE_GROUP VARBASE

PKG_USERS_VARS=		APACHE_USER
PKG_GROUPS_VARS=	APACHE_GROUP

PKG_SYSCONFSUBDIR=	phpmyadmin

FILES_SUBST+=	APACHE_GROUP=${APACHE_GROUP} APACHE_USER=${APACHE_USER}
FILES_SUBST+=	PMCONFDIR=${PMCONFDIR} PMVARDIR=${PMVARDIR}
MESSAGE_SUBST+=	PMCONFDIR=${PMCONFDIR} PMCONFFILE=${PMCONFFILE}

DOC_FILES=	ChangeLog CODE_OF_CONDUCT.md CONTRIBUTING.md DCO LICENSE \
		README RELEASE-DATE-${PKGVERSION_NOREV}

EXDIR=		${PREFIX}/share/examples/phpmyadmin
PMCONFDIR=	${PKG_SYSCONFDIR}
PMCONFFILE=	${PKG_SYSCONFDIR}/config.inc.php
PMDIR=		${PREFIX}/share/phpmyadmin
PMVARDIR=	${VARBASE}/phpmyadmin

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	/usr/bin/env php
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	vendor/bin/highlight-query vendor/bin/lint-query
REPLACE_FILES.php+=	vendor/phpmyadmin/sql-parser/bin/highlight-query
REPLACE_FILES.php+=	vendor/phpmyadmin/sql-parser/bin/lint-query
REPLACE_FILES.php+=	vendor/phpmyadmin/sql-parser/bin/tokenize-query

REPLACE_SH+=	vendor/twig/twig/drupal_test.sh

CONF_FILES+=	${EXDIR}/apache.conf ${PKG_SYSCONFDIR}/apache.conf

SRCS=		*.css *.ico *.php *.txt doc js libraries locale setup \
		sql templates themes vendor

NO_BUILD=		yes

SUBST_CLASSES+=		paths
SUBST_FILES.paths+=	${WRKDIR}/phpmyadmin.conf
SUBST_FILES.paths+=	${WRKSRC}/libraries/vendor_config.php
SUBST_VARS.paths=	PMDIR
SUBST_VARS.paths+=	PMVARDIR
SUBST_SED.paths+=	-e "s|@PMCONFDIR@|${PMCONFDIR}/|g"
SUBST_STAGE.paths=	post-configure

INSTALLATION_DIRS+=	${PREFIX}/share/doc/phpmyadmin \
			${PREFIX}/share/examples/phpmyadmin

post-extract:
	${CP} ${FILESDIR}/phpmyadmin.conf ${WRKDIR}

do-install:
	cd ${WRKSRC} && pax -rw ${SRCS} ${DESTDIR}${PMDIR}
	${INSTALL_DATA} ${WRKSRC}/config.sample.inc.php ${DESTDIR}${EXDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${DESTDIR}${EXDIR}
	${LN} -fs ${EXDIR} ${DESTDIR}${PMDIR}/examples
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${DOC_FILES} \
			${DESTDIR}${PREFIX}/share/doc/phpmyadmin
	${INSTALL_DATA} ${WRKDIR}/phpmyadmin.conf ${DESTDIR}${EXDIR}/apache.conf

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
