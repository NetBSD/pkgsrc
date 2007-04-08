# $NetBSD: Makefile,v 1.1.1.1 2007/04/08 17:04:08 adrianp Exp $
#

#		SVN build 508
DISTNAME=	roundcube-0.1-20070314
PKGNAME=	${DISTNAME:S/-0.1//}
CATEGORIES=	mail
MASTER_SITES=	http://www.farrokhi.net/roundcube/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://roundcube.net/
COMMENT=	Browser-based multilingual IMAP client

.include "../../lang/php/phpversion.mk"

DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=4.3.1:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=4.3.1:../../misc/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-imap>=4.3.1:../../mail/php-imap

USE_LANGUAGES=	# none
WRKSRC=		${WRKDIR}/roundcubemail

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	httpd

BUILD_DEFS+=	APACHE_USER APACHE_GROUP
RCDIR=		${PREFIX}/share/roundcube
EGDIR=		${PREFIX}/share/examples/roundcube
DOCDIR=		${PREFIX}/share/doc/roundcube
PAX_DIRS=	program skins

MESSAGE_SUBST+=	DOCDIR=${DOCDIR:Q} PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

CONF_FILES=		${EGDIR}/roundcube.conf ${PKG_SYSCONFDIR}/roundcube.conf
CONF_FILES_PERMS+=	${EGDIR}/db.inc.php ${RCDIR}/config/db.inc.php \
			${APACHE_USER} ${APACHE_GROUP} 0440
CONF_FILES_PERMS+=	${EGDIR}/main.inc.php ${RCDIR}/config/main.inc.php \
			${APACHE_USER} ${APACHE_GROUP} 0440

SUBST_CLASSES+=		files
SUBST_STAGE.files=	post-build
SUBST_FILES.files=	roundcube.conf
SUBST_SED.files=	-e "s|@RCDIR@|${RCDIR}|g"
SUBST_MESSAGE.files=	Fixing configuration files.

.include "options.mk"
.include "../../mk/apache.mk"

do-build:
	${CP} ${FILESDIR}/roundcube.conf ${WRKSRC}/roundcube.conf

do-install:
	${INSTALL_DATA_DIR} ${RCDIR}
	${INSTALL_DATA_DIR} ${RCDIR}/config
	${INSTALL_DATA_DIR} ${RCDIR}/program
	${INSTALL_DATA_DIR} ${RCDIR}/skins
	${INSTALL_DATA_DIR} ${RCDIR}/temp
	${INSTALL_DATA_DIR} ${RCDIR}/logs
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${EGDIR}/SQL
	${INSTALL_DATA_DIR} ${DOCDIR}

	${INSTALL_DATA} ${WRKSRC}/roundcube.conf ${EGDIR}/roundcube.conf
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADING ${DOCDIR}

	${INSTALL_DATA} ${WRKSRC}/SQL/*.sql ${EGDIR}/SQL/

	${INSTALL_DATA} ${WRKSRC}/.htaccess ${RCDIR}/
	${INSTALL_DATA} ${WRKSRC}/config/.htaccess ${RCDIR}/config/
	${INSTALL_DATA} ${WRKSRC}/temp/.htaccess ${RCDIR}/temp/
	${INSTALL_DATA} ${WRKSRC}/logs/.htaccess ${RCDIR}/logs/

	${INSTALL_DATA} ${WRKSRC}/index.php ${RCDIR}/

	${INSTALL_DATA} ${WRKSRC}/config/db.inc.php.dist ${EGDIR}/db.inc.php
	${INSTALL_DATA} ${WRKSRC}/config/main.inc.php.dist ${EGDIR}/main.inc.php

	${CHOWN} ${APACHE_USER}:${APACHE_GROUP} ${RCDIR}/temp/
	${CHOWN} ${APACHE_USER}:${APACHE_GROUP} ${RCDIR}/logs/

.for i in ${PAX_DIRS}
	cd ${WRKSRC}/${i} && ${PAX} -rw . ${RCDIR}/${i}
	${FIND} ${RCDIR}/${i} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	${FIND} ${RCDIR}/${i} -type d | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${RCDIR}/${i}
.endfor

.include "../../mk/bsd.pkg.mk"
