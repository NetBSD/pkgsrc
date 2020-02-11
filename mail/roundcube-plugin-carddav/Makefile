# $NetBSD: Makefile,v 1.1 2020/02/11 20:36:49 triaxx Exp $

DISTNAME=	carddav-3.0.3
PKGNAME=	${PHP_PKG_PREFIX}-roundcube-plugin-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=blind-coder/}
GITHUB_PROJECT=	rcmcarddav
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

HOMEPAGE=	https://www.benjamin-schieder.de/carddav.html
MAINTAINER=	triaxx@NetBSD.org
COMMENT=	CardDAV adapter for Roundcube
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"

NO_BUILD=	yes

DEPENDS+=	${PHP_PKG_PREFIX}-roundcube>=1.0.0:../../mail/roundcube

WRKSRC=		${WRKDIR}/carddav

DISTINFO_FILE=		distinfo

PKG_SYSCONFSUBDIR=	roundcube

WWW_USER?=		${APACHE_USER}
WWW_GROUP?=		${APACHE_GROUP}
PKG_GROUPS_VARS+=	WWW_GROUP
PKG_USERS_VARS=		WWW_USER
BUILD_DEFS+=		WWW_USER WWW_GROUP APACHE_USER APACHE_GROUP

RCDIR=			share/roundcube
CDDIR=			${RCDIR}/plugins/carddav
EGDIR=			share/examples/roundcube/plugins/carddav

CD_SUBDIRS=		dbmigrations localization skins vendor

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
SUBST_FILES.cfg=	carddav_common.php
SUBST_VARS.cfg=		PKG_SYSCONFDIR

do-install:
	${INSTALL_DATA} ${WRKSRC}/carddav.php \
		${DESTDIR}${PREFIX}/${CDDIR}/carddav.php
	${INSTALL_DATA} ${WRKSRC}/carddav_backend.php \
		${DESTDIR}${PREFIX}/${CDDIR}/carddav_backend.php
	${INSTALL_DATA} ${WRKSRC}/carddav_common.php \
		${DESTDIR}${PREFIX}/${CDDIR}/carddav_common.php
	${INSTALL_DATA} ${WRKSRC}/carddav_discovery.php \
		${DESTDIR}${PREFIX}/${CDDIR}/carddav_discovery.php
.for i in ${CD_SUBDIRS}
	cd ${WRKSRC}/${i} && ${FIND} . -type f -print | \
		pax -rw ${DESTDIR}${PREFIX}/${CDDIR}/${i}
	${FIND} ${DESTDIR}${PREFIX}/${CDDIR}/${i} -type f | \
		${XARGS} ${CHMOD} ${SHAREMODE}
	${FIND} ${DESTDIR}${PREFIX}/${CDDIR}/${i} -type d | \
		${XARGS} ${CHMOD} ${PKGDIRMODE}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} \
		${DESTDIR}${PREFIX}/${CDDIR}/${i}
.endfor
	${INSTALL_DATA} ${WRKSRC}/config.inc.php.dist \
		${DESTDIR}${PREFIX}/${EGDIR}/config.inc.php

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
