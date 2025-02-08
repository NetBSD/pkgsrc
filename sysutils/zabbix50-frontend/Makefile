# $NetBSD: Makefile,v 1.13 2025/02/08 03:54:13 taca Exp $

PKGREVISION=	2

PHP_VERSIONS_ACCEPTED=	74

.include "../../sysutils/zabbix50-server/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-frontend-${ZABBIX_DB_TYPE}-/}
COMMENT=	Zabbix PHP 7.4 frontend

DISTINFO_FILE=	${.CURDIR}/../../sysutils/zabbix50-server/distinfo
PATCHDIR=	${.CURDIR}/../../sysutils/zabbix50-server/patches

CONFLICTS+=	zabbix-frontend-[0-9]*

EGDIR=		share/examples/${PKGBASE}

USE_TOOLS+=		pax
NO_BUILD=		yes

CHECK_PORTABILITY_SKIP=	configure

REPLACE_SH+=	ui/locale/add_new_language.sh ui/locale/make_mo.sh \
		ui/locale/update_po.sh

.include "options.mk"

BUILD_DEFS+=		APACHE_GROUP APACHE_USER
PKG_GROUPS_VARS+=	${APACHE_GROUP}
PKG_USERS_VARS=		${APACHE_USER}

DEPENDS+=	${PHP_PKG_PREFIX}-bcmath>=${PHP_BASE_VERS}:../../math/php-bcmath
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=${PHP_BASE_VERS}:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-gettext>=${PHP_BASE_VERS}:../../devel/php-gettext
DEPENDS+=	${PHP_PKG_PREFIX}-ldap>=${PHP_BASE_VERS}:../../databases/php-ldap
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=${PHP_BASE_VERS}:../../converters/php-mbstring
.if ${ZABBIX_DB_TYPE} == "mysql"
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli>=${PHP_BASE_VERS}:../../databases/php-mysqli
.endif
.if ${ZABBIX_DB_TYPE} == "pgsql"
DEPENDS+=	${PHP_PKG_PREFIX}-pgsql>=${PHP_BASE_VERS}:../../databases/php-pgsql
.endif
DEPENDS+=	${PHP_PKG_PREFIX}-sockets>=${PHP_BASE_VERS}:../../net/php-sockets
DEPENDS+=	${PHP_PKG_PREFIX}-sysvsem>=${PHP_BASE_VERS}:../../devel/php-sysvsem

INSTALLATION_DIRS+=	${EGDIR} share/zabbix

do-install:
	rm -f ${WRKSRC}/ui/locale/*.orig
	cd ${WRKSRC}/ui; ${PAX} -rw . ${DESTDIR}${PREFIX}/share/zabbix/
	${INSTALL_DATA} ${FILESDIR}/httpd-zabbix.conf ${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/php-fpm-zabbix.conf ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
