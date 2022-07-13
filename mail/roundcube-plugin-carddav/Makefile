# $NetBSD: Makefile,v 1.8 2022/07/13 17:55:19 triaxx Exp $

DISTNAME=	carddav-v4.4.2
PKGNAME=	${PHP_PKG_PREFIX}-roundcube-plugin-${DISTNAME:S/-v/-/}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=mstilkerich/}
GITHUB_PROJECT=	rcmcarddav
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

HOMEPAGE=	https://github.com/mstilkerich/rcmcarddav
MAINTAINER=	triaxx@NetBSD.org
COMMENT=	CardDAV adapter for Roundcube
LICENSE=	gnu-gpl-v2

PHP_VERSIONS_INCOMPATIBLE=	56

USE_TOOLS+=	pax

.include "../../mk/bsd.prefs.mk"

NO_BUILD=	yes

REPLACE_PHP=	vendor/roundcube/plugin-installer/src/bin/rcubeinitdb.sh

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-composer-[0-9]*:../../devel/php-composer
DEPENDS+=	${PHP_PKG_PREFIX}-roundcube>=1.0.0:../../mail/roundcube

WRKSRC=		${WRKDIR}/carddav

PKG_SYSCONFSUBDIR=	roundcube

WWW_USER?=		${APACHE_USER}
WWW_GROUP?=		${APACHE_GROUP}
PKG_GROUPS_VARS+=	WWW_GROUP
PKG_USERS_VARS=		WWW_USER
BUILD_DEFS+=		WWW_USER WWW_GROUP APACHE_USER APACHE_GROUP

RCDIR=			share/roundcube
CDDIR=			${RCDIR}/plugins/carddav
EGDIR=			share/examples/roundcube/plugins/carddav

CD_SUBDIRS=		dbmigrations localization skins src vendor

.for d in ${CD_SUBDIRS}
INSTALLATION_DIRS+=	${CDDIR}/${d}
.endfor
INSTALLATION_DIRS+=	${EGDIR}

CONF_FILES_PERMS+=	${PREFIX}/${EGDIR}/config.inc.php \
			${PKG_SYSCONFDIR}/plugins/carddav/config.inc.php \
			${WWW_USER} ${WWW_GROUP} 0640

MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
SUBST_CLASSES+=		cfg
SUBST_STAGE.cfg=	pre-install
SUBST_MESSAGE.cfg=	Fixing configuration files.
SUBST_FILES.cfg=	carddav.php
SUBST_VARS.cfg=		PKG_SYSCONFDIR

post-extract:
	${CP} ${FILESDIR}/composer.lock ${WRKSRC}

do-install:
	cd ${WRKSRC} && ${PREFIX}/bin/composer install --no-dev
	${INSTALL_DATA} ${WRKSRC}/carddav.php \
		${DESTDIR}${PREFIX}/${CDDIR}/carddav.php
.for i in ${CD_SUBDIRS}
	cd ${WRKSRC}/${i} && ${FIND} . -type f -print | \
		${PAX} -rw ${DESTDIR}${PREFIX}/${CDDIR}/${i}
	${FIND} ${DESTDIR}${PREFIX}/${CDDIR}/${i} -type f | \
		${XARGS} ${CHMOD} ${SHAREMODE}
	${FIND} ${DESTDIR}${PREFIX}/${CDDIR}/${i} -type d | \
		${XARGS} ${CHMOD} ${PKGDIRMODE}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} \
		${DESTDIR}${PREFIX}/${CDDIR}/${i}
.endfor
	${INSTALL_DATA} ${WRKSRC}/config.inc.php.dist \
		${DESTDIR}${PREFIX}/${EGDIR}/config.inc.php

.include "../../lang/php/replace.mk"
.include "../../mk/bsd.pkg.mk"
