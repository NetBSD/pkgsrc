# $NetBSD: Makefile,v 1.12 2025/02/08 03:54:12 taca Exp $

PKGREVISION= 4
.include "../../sysutils/zabbix/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-frontend-/}
COMMENT=	Zabbix PHP frontend

PHP_VERSIONS_ACCEPTED=	56

USE_TOOLS+=		pax
NO_BUILD=		yes

do-configure:
	${DO_NADA}

REPLACE_SH+=	frontends/php/locale/*.sh

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		APACHE_GROUP APACHE_USER
PKG_GROUPS_VARS+=	${APACHE_GROUP}
PKG_USERS_VARS=		${APACHE_USER}

DEPENDS+=	${PHP_PKG_PREFIX}-bcmath>=${PHP_BASE_VERS}:../../math/php-bcmath
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=${PHP_BASE_VERS}:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-gettext>=${PHP_BASE_VERS}:../../devel/php-gettext
DEPENDS+=	${PHP_PKG_PREFIX}-ldap>=${PHP_BASE_VERS}:../../databases/php-ldap
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=${PHP_BASE_VERS}:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli>=${PHP_BASE_VERS}:../../databases/php-mysqli
DEPENDS+=	${PHP_PKG_PREFIX}-pgsql>=${PHP_BASE_VERS}:../../databases/php-pgsql
DEPENDS+=	${PHP_PKG_PREFIX}-sockets>=${PHP_BASE_VERS}:../../net/php-sockets
DEPENDS+=	${PHP_PKG_PREFIX}-sysvsem>=${PHP_BASE_VERS}:../../devel/php-sysvsem

INSTALLATION_DIRS+=	share/zabbix/frontend

do-install:
	rm -f ${WRKSRC}/frontends/php/locale/*.orig
	cd ${WRKSRC}/frontends; ${PAX} -rw php ${DESTDIR}${PREFIX}/share/zabbix/

.include "../../lang/php/json.mk"
.include "../../mk/bsd.pkg.mk"
