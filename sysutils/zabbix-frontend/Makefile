# $NetBSD: Makefile,v 1.2 2017/06/06 09:12:59 adam Exp $

.include "../../sysutils/zabbix/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-frontend-/}
COMMENT=	Zabbix PHP frontend

USE_TOOLS+=		pax
NO_CONFIGURE=		yes
NO_BUILD=		yes

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		APACHE_GROUP APACHE_USER
PKG_GROUPS_VARS+=	${APACHE_GROUP}
PKG_USERS_VARS=		${APACHE_USER}

DEPENDS+=	${PHP_PKG_PREFIX}-bcmath>=5.4.0:../../math/php-bcmath
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.4.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-gettext>=5.4.0:../../devel/php-gettext
DEPENDS+=	${PHP_PKG_PREFIX}-json>=5.4.0:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-ldap>=5.4.0:../../databases/php-ldap
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.4.0:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli>=5.4.0:../../databases/php-mysqli
DEPENDS+=	${PHP_PKG_PREFIX}-pgsql>=5.4.0:../../databases/php-pgsql
DEPENDS+=	${PHP_PKG_PREFIX}-sockets>=5.4.0:../../net/php-sockets
DEPENDS+=	${PHP_PKG_PREFIX}-sysvsem>=5.4.0:../../devel/php-sysvsem

INSTALLATION_DIRS+=	share/zabbix/frontend

do-install:
	cd ${WRKSRC}/frontends; ${PAX} -rw php ${DESTDIR}${PREFIX}/share/zabbix/

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
