# $NetBSD: Makefile,v 1.1 2014/12/12 12:52:47 fhajny Exp $

DISTNAME=	magento-1.9.1.0
CATEGORIES=	www finance
MASTER_SITES=	http://www.magentocommerce.com/downloads/assets/${PKGVERSION_NOREV}/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://www.magentocommerce.com/
COMMENT=	Feature-rich eCommerce platform
LICENSE=	osl

DEPENDS+=	${PHP_PKG_PREFIX}-curl-[0-9]*:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-dom-[0-9]*:../../textproc/php-dom
DEPENDS+=	${PHP_PKG_PREFIX}-gd-[0-9]*:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-iconv-[0-9]*:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-json-[0-9]*:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-mcrypt-[0-9]*:../../security/php-mcrypt
DEPENDS+=	${PHP_PKG_PREFIX}-mysql-[0-9]*:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql-[0-9]*:../../databases/php-pdo_mysql
DEPENDS+=	${PHP_PKG_PREFIX}-soap-[0-9]*:../../net/php-soap
DEPENDS+=	${PHP_PKG_PREFIX}-zlib-[0-9]*:../../archivers/php-zlib

WRKSRC=		${WRKDIR}/magento

USE_LANGUAGES=	# none
USE_TOOLS+=	pax
NO_BUILD=	yes

.include "../../lang/php/phpversion.mk"

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		VARBASE MAGENTO_DIR MAGENTO_OWN MAGENTO_GRP

MAGENTO_DIR?=		${VARBASE}/magento
MAGENTO_OWN?=		${APACHE_USER}
MAGENTO_GRP?=		${APACHE_GROUP}

PKG_USERS_VARS=		MAGENTO_OWN
PKG_GROUPS_VARS+=	MAGENTO_GRP
PKG_GROUPS=		${MAGENTO_GRP}
PKG_USERS=		${MAGENTO_OWN}:${MAGENTO_GRP}

MODULEFILES=	Cm_RedisSession.xml Mage_All.xml Mage_Api.xml Mage_Api2.xml	\
		Mage_Authorizenet.xml Mage_Bundle.xml Mage_Captcha.xml		\
		Mage_Centinel.xml Mage_Compiler.xml Mage_Connect.xml		\
		Mage_CurrencySymbol.xml Mage_Downloadable.xml			\
		Mage_ImportExport.xml Mage_Oauth.xml Mage_PageCache.xml		\
		Mage_Persistent.xml Mage_Weee.xml Mage_Widget.xml		\
		Mage_XmlConnect.xml Phoenix_Moneybookers.xml

CONF_FILES_PERMS+=	share/examples/magento/local.xml.template		\
			${PKG_SYSCONFDIR}/local.xml.template			\
			${MAGENTO_OWN} ${MAGENTO_GRP} 0640
CONF_FILES_PERMS+=	share/examples/magento/config.xml 			\
			${PKG_SYSCONFDIR}/config.xml				\
			${MAGENTO_OWN} ${MAGENTO_GRP} 0640
.for file in ${MODULEFILES}
CONF_FILES_PERMS+=	share/examples/magento/modules/${file}			\
			${PKG_SYSCONFDIR}/modules/${file}			\
			${MAGENTO_OWN} ${MAGENTO_GRP} 0640
.endfor

FILES_SUBST+=		MAGENTO_OWN=${MAGENTO_OWN} MAGENTO_GRP=${MAGENTO_GRP}
INSTALLATION_DIRS+=	share/examples/magento share/magento
PKG_SYSCONFSUBDIR=	magento
PKG_SYSCONFDIR_PERMS=	${MAGENTO_OWN} ${MAGENTO_GRP} 0750
MAKE_DIRS_PERMS+=	${PKG_SYSCONFDIR}/modules ${MAGENTO_OWN} ${MAGENTO_GRP} 0750
OWN_DIRS_PERMS+=	${MAGENTO_DIR} ${MAGENTO_OWN} ${MAGENTO_GRP} 0750

do-install:
	cd ${WRKSRC} && pax -rw -p pp * ${DESTDIR}${PREFIX}/share/magento
	cd ${DESTDIR}${PREFIX}/share/magento/app/etc && \
		${MV} * ${DESTDIR}${PREFIX}/share/examples/magento
	${CHMOD} -R g+w ${DESTDIR}${PREFIX}/share/magento/media
	${CHMOD} -R g+w ${DESTDIR}${PREFIX}/share/examples/magento
	${RM} -rf ${DESTDIR}${PREFIX}/share/magento/app/etc
	${RM} -rf ${DESTDIR}${PREFIX}/share/magento/var
	${LN} -sf ${PKG_SYSCONFDIR} ${DESTDIR}${PREFIX}/share/magento/app/etc
	${LN} -sf ${MAGENTO_DIR} ${DESTDIR}${PREFIX}/share/magento/var

.include "../../mk/bsd.pkg.mk"
