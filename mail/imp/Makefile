# $NetBSD: Makefile,v 1.29 2005/05/01 17:36:26 adrianp Exp $

DISTNAME=	imp-3.2.8
CATEGORIES=	mail www
MASTER_SITES=	ftp://ftp.horde.org/pub/imp/tarballs/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.horde.org/imp/
COMMENT=	Internet Messaging Program

CONFLICTS+=	imp-4.*

DEPENDS+=	horde>=2.2.4:../../www/horde
DEPENDS+=	php-imap>4.0.0:../../mail/php-imap

DOCDIR=		${PREFIX}/share/doc/imp
EGDIR=		${PREFIX}/share/examples/imp
HORDEDIR=	${PREFIX}/share/horde
IMPDIR=		${HORDEDIR}/imp

MESSAGE_SUBST+=	IMPDIR=${IMPDIR}
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

USE_PKGINSTALL=		yes
PKG_SYSCONFSUBDIR?=	httpd

CONF_FILES=	${EGDIR}/imp.conf ${PKG_SYSCONFDIR}/imp.conf
CONF_FILES+=	${IMPDIR}/config/conf.php.dist			\
		${IMPDIR}/config/conf.php
CONF_FILES+=	${IMPDIR}/config/servers.php.dist			\
		${IMPDIR}/config/servers.php
SUPPORT_FILES+=	${IMPDIR}/config/filter.txt.dist			\
		${IMPDIR}/config/filter.txt
SUPPORT_FILES+=	${IMPDIR}/config/header.txt.dist			\
		${IMPDIR}/config/header.txt
SUPPORT_FILES+=	${IMPDIR}/config/html.php.dist				\
		${IMPDIR}/config/html.php
SUPPORT_FILES+=	${IMPDIR}/config/menu.php.dist		\
		${IMPDIR}/config/menu.php
SUPPORT_FILES+=	${IMPDIR}/config/mime_drivers.php.dist				\
		${IMPDIR}/config/mime_drivers.php
SUPPORT_FILES+=	${IMPDIR}/config/motd.php.dist			\
		${IMPDIR}/config/motd.php
SUPPORT_FILES+=	${IMPDIR}/config/prefs.php.dist			\
		${IMPDIR}/config/prefs.php
SUPPORT_FILES+=	${IMPDIR}/config/trailer.txt.dist			\
		${IMPDIR}/config/trailer.txt

do-build:
	${FIND} ${WRKSRC} -name .htaccess -print | ${XARGS} ${RM} -f
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM} -f
	${FIND} ${WRKSRC} -name "*.pl" -print | ${XARGS} ${CHMOD} +x
	${FIND} ${WRKSRC} -name "*.sh" -print | ${XARGS} ${CHMOD} +x

pre-install:
	${SED}	-e "s|@IMPDIR@|${IMPDIR}|g"				\
		${FILESDIR}/imp.conf.dist > ${WRKDIR}/imp.conf.dist

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${IMPDIR}
	cd ${WRKDIR}; ${INSTALL_DATA} imp.conf.dist ${EGDIR}/imp.conf
	cd ${WRKSRC}; ${INSTALL_DATA} COPYING README docs/* ${DOCDIR}
	cd ${WRKSRC}; ${CP} -R graphics lib locale po scripts templates ${IMPDIR}
	${INSTALL_DATA_DIR} ${IMPDIR}/config
	cd ${WRKSRC}/config; ${INSTALL_DATA} * ${IMPDIR}/config
	cd ${WRKSRC}; ${INSTALL_DATA} *.php ${IMPDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${IMPDIR}
	${CHMOD} -R a-w ${IMPDIR}

.include "../../mk/bsd.pkg.mk"
