# $NetBSD: Makefile,v 1.19 2024/02/19 15:43:34 taca Exp $

DISTNAME=		phabricator-20170609
PKGREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=phacility/}
# Track the stable branch
GITHUB_PROJECT=		phabricator
GITHUB_TAG=		5885704800a97aadf47aee5654ff2647b40fb4ad

MAINTAINER=		roy@NetBSD.org
HOMEPAGE=		http://phabricator.com/
COMMENT=		Open software engineering platform
LICENSE=		apache-2.0

USE_TOOLS+=		pax bash:run
EXTRACT_USING=		bsdtar

.include "../../lang/php/phpversion.mk"
DEPENDS+=		${PHP_PKG_PREFIX}-curl-[0-9]*:../../www/php-curl
DEPENDS+=		${PHP_PKG_PREFIX}-mbstring-[0-9]*:../../converters/php-mbstring
DEPENDS+=		${PHP_PKG_PREFIX}-iconv-[0-9]*:../../converters/php-iconv
DEPENDS+=		${PHP_PKG_PREFIX}-mysqli-[0-9]*:../../databases/php-mysqli
DEPENDS+=		${PHP_PKG_PREFIX}-pcntl-[0-9]*:../../devel/php-pcntl
DEPENDS+=		${PHP_PKG_PREFIX}-posix-[0-9]*:../../devel/php-posix
DEPENDS+=		${PHP_PKG_PREFIX}-gd-[0-9]*:../../graphics/php-gd
DEPENDS+=		${PHP_PKG_PREFIX}-zlib-[0-9]*:../../archivers/php-zlib
DEPENDS+=		${PHP_PKG_PREFIX}-opcache-[0-9]*:../../devel/php-opcache
.if ${PKG_PHP_MAJOR_VERS} == "5"
DEPENDS+=		${PHP_PKG_PREFIX}-apcu<5:../../www/php-apcu4
.else
DEPENDS+=		${PHP_PKG_PREFIX}-apcu>=5:../../www/php-apcu
.endif
DEPENDS+=		libphutil-[0-9]*:../../devel/libphutil
DEPENDS+=		arcanist-[0-9]*:../../devel/arcanist

SUBST_CLASSES+=		php
SUBST_MESSAGE.php=	Fixing PHP path
SUBST_STAGE.php=	post-configure
SUBST_FILES.php=	externals/httpful/build
SUBST_FILES.php+=	externals/restful/build-phar
SUBST_SED.php=		-e 's,/usr/bin/php,${PREFIX}/bin/php,'

SUBST_CLASSES+=		php_env
SUBST_MESSAGE.php_env=	Fixing PHP path
SUBST_STAGE.php_env=	post-configure
SUBST_FILES.php_env+=	scripts/almanac/manage_almanac.php \
			scripts/cache/manage_cache.php \
			scripts/celerity/*.php \
			scripts/daemon/*.php \
			scripts/diviner/diviner.php \
			scripts/drydock/drydock_control.php \
			scripts/fact/manage_facts.php \
			scripts/files/manage_files.php \
			scripts/lipsum/manage_lipsum.php \
			scripts/mail/*.php \
			scripts/people/manage_people.php \
			scripts/repository/*.php \
			scripts/search/manage_search.php \
			scripts/setup/*.php \
			scripts/sms/manage_sms.php \
			scripts/sql/manage_storage.php \
			scripts/ssh/*.php \
			scripts/symbols/*.php \
			scripts/user/*.php \
			scripts/util/*.php \
			support/aphlict/server/aphlict_launcher.php
SUBST_SED.php_env=	-e 's,/usr/bin/env php,${PREFIX}/bin/php,'

REPLACE_BASH+=		scripts/install/install_rhel-derivs.sh \
			scripts/install/install_ubuntu.sh

NO_BUILD=		yes

RCD_SCRIPTS=		phd

PHABRICATOR_DIR=	share/phabricator

INSTALLATION_DIRS+=	${PHABRICATOR_DIR}

CHECK_INTERPRETER_SKIP+=	${PHABRICATOR_DIR}/externals/wordlist/password.lst

CHMOD_FILES=		conf LICENSE NOTICE README.md externals resources src \
			support webroot scripts/__init_script__.php scripts/fpm/warmup.php

post-extract:
	cd ${WRKSRC} && \
	${FIND} ${CHMOD_FILES} -type f \
		\! -name aphlict_launcher.php \
		-exec ${CHMOD} -x \{\} \;

do-install:
	cd ${WRKSRC} && \
	${PAX} -rw * -s',.*\.orig$$,,' \
		${DESTDIR}${PREFIX}/${PHABRICATOR_DIR}

.include "../../mk/bsd.pkg.mk"
