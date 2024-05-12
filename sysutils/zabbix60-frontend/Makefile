# $NetBSD: Makefile,v 1.7 2024/05/12 14:36:45 taca Exp $

PKGREVISION= 1
.include "../../sysutils/zabbix60-server/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-frontend-${ZABBIX_DB_TYPE}-/}
COMMENT=	Zabbix PHP 8 frontend

DISTINFO_FILE=	${.CURDIR}/../../sysutils/zabbix60-server/distinfo

CONFLICTS+=	zabbix-frontend-[0-9]*

PHP_VERSIONS_ACCEPTED=	81 82

EGDIR=		share/examples/${PKGBASE}

USE_TOOLS+=		pax
NO_BUILD=		yes
NO_CONFIGURE=		yes

REPLACE_SH+=	ui/locale/*.sh

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

BUILD_DEFS+=		APACHE_GROUP APACHE_USER
PKG_GROUPS_VARS+=	${APACHE_GROUP}
PKG_USERS_VARS=		${APACHE_USER}

DEPENDS+=	${PHP_PKG_PREFIX}-bcmath>=7.2.0:../../math/php-bcmath
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=7.2.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-gettext>=7.2.0:../../devel/php-gettext
DEPENDS+=	${PHP_PKG_PREFIX}-ldap>=7.2.0:../../databases/php-ldap
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=7.2.0:../../converters/php-mbstring
.if ${ZABBIX_DB_TYPE} == "mysql"
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli>=7.2.0:../../databases/php-mysqli
.endif
.if ${ZABBIX_DB_TYPE} == "pgsql"
DEPENDS+=	${PHP_PKG_PREFIX}-pgsql>=7.2.0:../../databases/php-pgsql
.endif
DEPENDS+=	${PHP_PKG_PREFIX}-sockets>=7.2.0:../../net/php-sockets
DEPENDS+=	${PHP_PKG_PREFIX}-sysvsem>=7.2.0:../../devel/php-sysvsem

INSTALLATION_DIRS+=	${EGDIR} share/zabbix

post-patch: replace-interpreter

do-install:
	rm -f ${WRKSRC}/ui/locale/*.orig
	cd ${WRKSRC}/ui; ${PAX} -rw . ${DESTDIR}${PREFIX}/share/zabbix/
	${INSTALL_DATA} ${FILESDIR}/httpd-zabbix.conf ${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/php-fpm-zabbix.conf ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../lang/php/json.mk"
.include "../../mk/configure/replace-interpreter.mk"
.include "../../mk/bsd.pkg.mk"
