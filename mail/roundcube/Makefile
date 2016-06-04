# $NetBSD: Makefile,v 1.80.2.1 2016/06/04 19:39:34 bsiegert Exp $

DISTNAME=	roundcubemail-1.1.5
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME:S/mail-/-/}
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=   ${MASTER_SITE_GITHUB:=roundcube/}
GITHUB_PROJECT= roundcubemail
GITHUB_RELEASE= 1.1.5
GITHUB_TYPE=    release
DIST_SUBDIR=	roundcubemail-1.1.5

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://roundcube.net/
COMMENT=	Browser-based multilingual IMAP client
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=${PHP_BASE_VERS}:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-dom>=${PHP_BASE_VERS}:../../textproc/php-dom
DEPENDS+=	${PHP_PKG_PREFIX}-exif>=${PHP_BASE_VERS}:../../graphics/php-exif
DEPENDS+=	${PHP_PKG_PREFIX}-intl>=${PHP_BASE_VERS}:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-json>=${PHP_BASE_VERS}:../../textproc/php-json

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_Sieve>=1.3.2:../../net/pear-Net_Sieve
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_SMTP>=1.4.2:../../net/pear-Net_SMTP
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_IDNA2>=0.1.1:../../net/pear-Net_IDNA2
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Mail_Mime>=1.8.1:../../mail/pear-Mail_Mime
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Mail_mimeDecode>=1.5.5:../../mail/pear-Mail_mimeDecode
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Auth_SASL>=1.0.3:../../mail/pear-Auth_SASL

PHP_VERSIONS_ACCEPTED=	55 56

USE_LANGUAGES=		# none
USE_TOOLS+=		pax
NO_BUILD=		yes

INSTALLATION_DIRS=	${RCDIR}/plugins ${RCDIR}/program ${RCDIR}/skins
INSTALLATION_DIRS+=	${RCDIR}/bin ${RCDIR}/SQL ${DOCDIR} ${EGDIR}

.include "../../lang/php/phpversion.mk"

PKG_SYSCONFSUBDIR?=	roundcube

PKG_GROUPS_VARS+=	WWW_GROUP
PKG_USERS_VARS=		WWW_USER
BUILD_DEFS+=		VARBASE WWW_USER WWW_GROUP APACHE_USER APACHE_GROUP

RCDIR=			${PREFIX}/share/roundcube
EGDIR=			${PREFIX}/share/examples/roundcube
DOCDIR=			${PREFIX}/share/doc/roundcube
PAX_DIRS=		plugins program skins installer
SQL_DIRS=		mssql mysql oracle postgres sqlite

CONF_PLUGINS=		acl additional_message_headers help \
			http_authentication jqueryui managesieve \
			newmail_notifier password redundant_attachments \
			squirrelmail_usercopy zipdownload

MESSAGE_SUBST+=		DOCDIR=${DOCDIR} PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
MESSAGE_SUBST+=		VARBASE=${VARBASE} RCDIR=${RCDIR}
FILES_SUBST+=		RCDIR=${RCDIR}

OWN_DIRS+=		${PKG_SYSCONFDIR}
OWN_DIRS_PERMS+=	${VARBASE}/log/roundcube \
			${WWW_USER} ${WWW_GROUP} 0750
OWN_DIRS_PERMS+=	${VARBASE}/spool/roundcube \
			${WWW_USER} ${WWW_GROUP} 0750
OWN_DIRS_PERMS+=	${VARBASE}/tmp/roundcube \
			${WWW_USER} ${WWW_GROUP} 0750

CONF_FILES=		${EGDIR}/roundcube.conf \
			${PKG_SYSCONFDIR}/roundcube.conf
CONF_FILES+=		${EGDIR}/mimetypes.php \
			${PKG_SYSCONFDIR}/mimetypes.php
CONF_FILES_PERMS+=	${EGDIR}/config.inc.php \
			${PKG_SYSCONFDIR}/config.inc.php \
			${WWW_USER} ${WWW_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/defaults.inc.php \
			${PKG_SYSCONFDIR}/defaults.inc.php \
			${WWW_USER} ${WWW_GROUP} 0640

.for f in ${CONF_PLUGINS}
CONF_FILES_PERMS+=	${EGDIR}/plugins/${f}/config.inc.php \
			${RCDIR}/plugins/${f}/config.inc.php \
			${WWW_USER} ${WWW_GROUP} 0640
.endfor

SUBST_CLASSES+=		files
SUBST_STAGE.files=	do-configure
SUBST_MESSAGE.files=	Fixing configuration files.
SUBST_FILES.files=	roundcube.conf
SUBST_FILES.files+=	config/config.inc.php.sample
SUBST_FILES.files+=	installer/index.php
SUBST_FILES.files+=	program/include/iniset.php
SUBST_FILES.files+=	program/lib/Roundcube/rcube_mime.php
SUBST_SED.files=	-e "s|@RCDIR@|${RCDIR}|g"
SUBST_SED.files+=	-e "s|@VARBASE@|${VARBASE}|g"
SUBST_SED.files+=	-e "s|@PKG_EXAMPLES@|${PREFIX}/share/examples/roundcube|g"
SUBST_SED.files+=	-e "s|@PKG_SYSCONFBASE@|${PKG_SYSCONFBASE}|g"
SUBST_SED.files+=	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	/usr/bin/env php
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	bin/*.sh

REPLACE_PYTHON=		plugins/password/helpers/chpass-wrapper.py

post-extract:
	${CP} ${FILESDIR}/${WWW_CONF_FILE} ${WRKSRC}/roundcube.conf

do-install:
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADING ${DESTDIR}${DOCDIR}

	${INSTALL_DATA} ${WRKSRC}/.htaccess ${DESTDIR}${RCDIR}/
	${INSTALL_DATA} ${WRKSRC}/index.php ${DESTDIR}${RCDIR}/
	${INSTALL_DATA} ${WRKSRC}/robots.txt ${DESTDIR}${RCDIR}/

	${INSTALL_DATA} ${WRKSRC}/SQL/*.sql ${DESTDIR}${RCDIR}/SQL/
.for i in ${SQL_DIRS}
	${INSTALL_DATA_DIR} ${DESTDIR}${RCDIR}/SQL/${i}
	${INSTALL_DATA} ${WRKSRC}/SQL/${i}/*.sql ${DESTDIR}${RCDIR}/SQL/${i}
.endfor

	${INSTALL_DATA} ${WRKSRC}/roundcube.conf \
		${DESTDIR}${EGDIR}/roundcube.conf
	${INSTALL_DATA} ${WRKSRC}/config/mimetypes.php \
		${DESTDIR}${EGDIR}/mimetypes.php
	${INSTALL_DATA} ${WRKSRC}/config/config.inc.php.sample \
		${DESTDIR}${EGDIR}/config.inc.php
	${INSTALL_DATA} ${WRKSRC}/config/defaults.inc.php \
		${DESTDIR}${EGDIR}/defaults.inc.php

	${INSTALL_SCRIPT} ${WRKSRC}/bin/*.sh ${DESTDIR}${RCDIR}/bin/

.for i in ${PAX_DIRS}
	${INSTALL_DATA_DIR} ${DESTDIR}${RCDIR}/${i}
	cd ${WRKSRC}/${i} && ${FIND} . -type f \! -name "*.orig" -print | \
		${PAX} -rw ${DESTDIR}${RCDIR}/${i}
	${FIND} ${DESTDIR}${RCDIR}/${i} -type f | \
		${XARGS} ${CHMOD} ${SHAREMODE}
	${FIND} ${DESTDIR}${RCDIR}/${i} -type d | \
		${XARGS} ${CHMOD} ${PKGDIRMODE}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${RCDIR}/${i}
.endfor

.for f in ${CONF_PLUGINS}
	${MKDIR} ${DESTDIR}${EGDIR}/plugins/${f}
	${TEST} -f ${DESTDIR}${EGDIR}/plugins/${f}/config.inc.php || \
		${MV} ${DESTDIR}${RCDIR}/plugins/${f}/config.inc.php.dist \
			${DESTDIR}${EGDIR}/plugins/${f}/config.inc.php
.endfor

.include "options.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
