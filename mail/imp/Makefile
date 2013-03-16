# $NetBSD: Makefile,v 1.59 2013/03/16 07:21:20 obache Exp $

DISTNAME=	imp-h3-${IMPVER}
PKGNAME=	imp-${IMPVER}
PKGREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	http://ftp.horde.org/pub/imp/ \
		ftp://ftp.horde.org/pub/imp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.horde.org/imp/
COMMENT=	Internet Messaging Program
LICENSE=	gnu-gpl-v2

CONFLICTS+=	imp-3.*{,nb*}

DEPENDS+=	horde>=3.2:../../www/horde
DEPENDS+=	${PHP_PKG_PREFIX}-imap>4.3.3:../../mail/php-imap
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Mail-[0-9]*:../../mail/pear-Mail
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Mail_mimeDecode-[0-9]*:../../mail/pear-Mail_mimeDecode

USE_TOOLS+=	pax

PKG_DESTDIR_SUPPORT=	destdir

.include "../../mk/bsd.prefs.mk"

DOCDIR=		${PREFIX}/share/doc/imp
EGDIR=		${PREFIX}/share/examples/imp
HORDEDIR=	${PREFIX}/share/horde
IMPDIR=		${HORDEDIR}/imp
IMPVER=		4.3.11
PAXDIRS=	lib locale po scripts templates themes js

WRKSRC=			${WRKDIR}/${DISTNAME}
PKG_USERS_VARS+=	APACHE_USER
BUILD_DEFS+=		APACHE_USER

MESSAGE_SUBST+=	IMPDIR=${IMPDIR}
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

PKG_SYSCONFSUBDIR?=	httpd

CONF_FILES=		${EGDIR}/imp.conf ${PKG_SYSCONFDIR}/imp.conf
CONF_FILES+=		${IMPDIR}/config/servers.php.dist \
			${IMPDIR}/config/servers.php
CONF_FILES_PERMS+=	${IMPDIR}/config/conf.xml.dist \
			${IMPDIR}/config/conf.xml \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${IMPDIR}/config/filter.txt.dist \
			${IMPDIR}/config/filter.txt \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${IMPDIR}/config/header.php.dist \
			${IMPDIR}/config/header.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${IMPDIR}/config/menu.php.dist \
			${IMPDIR}/config/menu.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${IMPDIR}/config/mime_drivers.php.dist \
			${IMPDIR}/config/mime_drivers.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${IMPDIR}/config/motd.php.dist \
			${IMPDIR}/config/motd.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${IMPDIR}/config/prefs.php.dist \
			${IMPDIR}/config/prefs.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${IMPDIR}/config/trailer.txt.dist \
			${IMPDIR}/config/trailer.txt \
			${APACHE_USER} ${ROOT_GROUP} 0440

SUBST_CLASSES+=		files
SUBST_STAGE.files=	post-build
SUBST_FILES.files=	imp.conf.dist
SUBST_SED.files=	-e "s|@IMPDIR@|${IMPDIR}|g"
SUBST_MESSAGE.files=	Fixing configuration files.

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*/bin/php
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	scripts/bounce_spam.php \
			scripts/upgrades/convert_vfolders.php

.include "options.mk"

do-build:
	${CP} ${FILESDIR}/imp.conf.dist ${WRKSRC}/imp.conf.dist
	${CP} ${WRKSRC}/config/conf.xml ${WRKSRC}/config/conf.xml.dist
	${FIND} ${WRKSRC} -name .htaccess -print | ${XARGS} ${RM} -f

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${IMPDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${IMPDIR}/config
	${INSTALL_DATA} ${WRKSRC}/imp.conf.dist ${DESTDIR}${EGDIR}/imp.conf
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DESTDIR}${DOCDIR}
.for d in ${PAXDIRS}
		${INSTALL_DATA_DIR} ${DESTDIR}${IMPDIR}/${d}
.endfor
.for d in ${PAXDIRS}
		cd ${WRKSRC}/${d} && pax -rwpam . ${DESTDIR}${IMPDIR}/${d}
.endfor
	${INSTALL_DATA} ${WRKSRC}/config/*.dist ${DESTDIR}${IMPDIR}/config
	${INSTALL_DATA} ${WRKSRC}/*.php ${DESTDIR}${IMPDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${IMPDIR}
	${FIND} ${DESTDIR}${IMPDIR} -type d -print | \
	${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${DESTDIR}${IMPDIR} -type f -print | \
	${XARGS} ${CHMOD} ${SHAREMODE}
	${CHOWN} ${APACHE_USER}:${ROOT_GROUP} ${DESTDIR}${IMPDIR}/config
	${CHMOD} 0750 ${DESTDIR}${IMPDIR}/config

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
