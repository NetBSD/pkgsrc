# $NetBSD: Makefile,v 1.20 2025/02/08 03:36:57 taca Exp $

DISTNAME=	phabricator-20170609
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=phacility/}
# Track the stable branch
GITHUB_PROJECT=	phabricator
GITHUB_TAG=	5885704800a97aadf47aee5654ff2647b40fb4ad

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	http://phabricator.com/
COMMENT=	Open software engineering platform
LICENSE=	apache-2.0

USE_TOOLS+=	pax bash:run
EXTRACT_USING=	bsdtar

DEPENDS+=	${PHP_PKG_PREFIX}-curl>=${PHP_BASE_VERS}:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=${PHP_BASE_VERS}:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=${PHP_BASE_VERS}:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli>=${PHP_BASE_VERS}:../../databases/php-mysqli
DEPENDS+=	${PHP_PKG_PREFIX}-pcntl>=${PHP_BASE_VERS}:../../devel/php-pcntl
DEPENDS+=	${PHP_PKG_PREFIX}-posix>=${PHP_BASE_VERS}:../../devel/php-posix
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=${PHP_BASE_VERS}:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=${PHP_BASE_VERS}:../../archivers/php-zlib
DEPENDS+=	${PHP_PKG_PREFIX}-opcache>=${PHP_BASE_VERS}:../../devel/php-opcache
DEPENDS+=	libphutil-[0-9]*:../../devel/libphutil
DEPENDS+=	arcanist-[0-9]*:../../devel/arcanist

REPLACE_PHP=	externals/httpful/build
REPLACE_PHP+=	externals/restful/build-phar
REPLACE_PHP+=	scripts/almanac/manage_almanac.php \
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

REPLACE_BASH+=	scripts/install/install_rhel-derivs.sh \
		scripts/install/install_ubuntu.sh

.include "../../lang/php/phpversion.mk"
.if ${PHP_VER} < 70
DEPENDS+=		${PHP_PKG_PREFIX}-apcu<5:../../www/php-apcu4
.else
DEPENDS+=		${PHP_PKG_PREFIX}-apcu>=5:../../www/php-apcu
.endif

NO_BUILD=	yes
 
RCD_SCRIPTS=	phd

CHMOD_FILES=	conf LICENSE NOTICE README.md externals resources src \
		support webroot scripts/__init_script__.php \
		scripts/fpm/warmup.php

PHABRICATOR_DIR=	share/phabricator
INSTALLATION_DIRS+=	${PHABRICATOR_DIR}

CHECK_INTERPRETER_SKIP+=	${PHABRICATOR_DIR}/externals/wordlist/password.lst

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
