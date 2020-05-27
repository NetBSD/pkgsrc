# $NetBSD: Makefile,v 1.11 2020/05/27 19:37:40 wiz Exp $

DISTNAME=	magento-1.9.2.2
PKGREVISION=	1
CATEGORIES=	www finance
# Upstream temporarily removed the option to download directly
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/fhajny/magento/
# MASTER_SITES=	http://www.magentocommerce.com/downloads/assets/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.magentocommerce.com/
COMMENT=	Feature-rich eCommerce platform
LICENSE=	osl

DIST_SUBDIR=	magento
PATCH_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/fhajny/magento/
PATCHFILES=	# none sofar
EXTRACT_DIR=	${WRKDIR}/magento

DEPENDS+=	${PHP_PKG_PREFIX}-curl-[0-9]*:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-gd-[0-9]*:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-iconv-[0-9]*:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-json-[0-9]*:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-mcrypt-[0-9]*:../../security/php-mcrypt
DEPENDS+=	${PHP_PKG_PREFIX}-mysql-[0-9]*:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql-[0-9]*:../../databases/php-pdo_mysql
DEPENDS+=	${PHP_PKG_PREFIX}-soap-[0-9]*:../../net/php-soap
DEPENDS+=	${PHP_PKG_PREFIX}-zlib-[0-9]*:../../archivers/php-zlib

PHP_VERSIONS_ACCEPTED=	56

WRKSRC=		${WRKDIR}/magento

USE_LANGUAGES=	# none
USE_TOOLS+=	date pax
NO_BUILD=	yes

.include "../../lang/php/phpversion.mk"

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		VARBASE MAGENTO_DIR MAGENTO_OWN MAGENTO_GRP
BUILD_DEFS+=		APACHE_USER APACHE_GROUP

MAGENTO_DIR?=		${VARBASE}/magento
MAGENTO_OWN?=		${APACHE_USER}
MAGENTO_GRP?=		${APACHE_GROUP}

PKG_USERS_VARS=		MAGENTO_OWN
PKG_GROUPS_VARS+=	MAGENTO_GRP
PKG_GROUPS=		${MAGENTO_GRP}
PKG_USERS=		${MAGENTO_OWN}:${MAGENTO_GRP}

MODULEFILES=	Cm_RedisSession.xml Mage_All.xml Mage_Api.xml Mage_Api2.xml \
		Mage_Authorizenet.xml Mage_Bundle.xml Mage_Captcha.xml \
		Mage_Centinel.xml Mage_Compiler.xml Mage_Connect.xml \
		Mage_CurrencySymbol.xml Mage_Downloadable.xml \
		Mage_ImportExport.xml Mage_Oauth.xml Mage_PageCache.xml \
		Mage_Persistent.xml Mage_Weee.xml Mage_Widget.xml \
		Mage_XmlConnect.xml Phoenix_Moneybookers.xml

CONF_FILES_PERMS+=	share/examples/magento/applied.patches.list \
			${PKG_SYSCONFDIR}/applied.patches.list \
			${MAGENTO_OWN} ${MAGENTO_GRP} 0640
CONF_FILES_PERMS+=	share/examples/magento/local.xml.template \
			${PKG_SYSCONFDIR}/local.xml.template \
			${MAGENTO_OWN} ${MAGENTO_GRP} 0640
CONF_FILES_PERMS+=	share/examples/magento/config.xml \
			${PKG_SYSCONFDIR}/config.xml \
			${MAGENTO_OWN} ${MAGENTO_GRP} 0640
.for file in ${MODULEFILES}
CONF_FILES_PERMS+=	share/examples/magento/modules/${file} \
			${PKG_SYSCONFDIR}/modules/${file} \
			${MAGENTO_OWN} ${MAGENTO_GRP} 0640
.endfor

FILES_SUBST+=		MAGENTO_OWN=${MAGENTO_OWN} MAGENTO_GRP=${MAGENTO_GRP}
INSTALLATION_DIRS+=	share/examples/magento share/magento
PKG_SYSCONFSUBDIR=	magento
PKG_SYSCONFDIR_PERMS=	${MAGENTO_OWN} ${MAGENTO_GRP} 0750
MAKE_DIRS_PERMS+=	${PKG_SYSCONFDIR}/modules ${MAGENTO_OWN} ${MAGENTO_GRP} 0750
OWN_DIRS_PERMS+=	${MAGENTO_DIR} ${MAGENTO_OWN} ${MAGENTO_GRP} 0750

post-extract:
	${CHMOD} -R g-w,o-w ${WRKSRC}

# Make note of the patches applied, same way the upstream patch scripts do
post-patch:
	${TOUCH} ${WRKSRC}/app/etc/applied.patches.list
.for file in ${PATCHFILES}
	${ECHO_N} `${DATE} -u +"%F %T UTC"`' | ' >> ${WRKSRC}/app/etc/applied.patches.list
	${GREP} '^SUPEE-' ${DISTDIR}/${DIST_SUBDIR}/${file} >> ${WRKSRC}/app/etc/applied.patches.list
.endfor

pre-install:
	${FIND} ${WRKSRC} -type f -name "*.orig_dist" | ${XARGS} ${RM} -f

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
