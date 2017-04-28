# $NetBSD: Makefile,v 1.88 2017/04/28 13:48:29 taca Exp $

DISTNAME=	roundcubemail-${RC_VERS}
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME:S/mail-/-/}

MAINTAINER=	taca@NetBSD.org
COMMENT=	Browser-based multilingual IMAP client
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=${PHP_BASE_VERS}:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-exif>=${PHP_BASE_VERS}:../../graphics/php-exif
DEPENDS+=	${PHP_PKG_PREFIX}-intl>=${PHP_BASE_VERS}:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-json>=${PHP_BASE_VERS}:../../textproc/php-json

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_Sieve>=1.3.2:../../net/pear-Net_Sieve
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_SMTP>=1.7.1:../../net/pear-Net_SMTP
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_IDNA2>=0.1.1:../../net/pear-Net_IDNA2
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Mail_Mime>=1.10.0:../../mail/pear-Mail_Mime
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Auth_SASL>=1.0.6:../../mail/pear-Auth_SASL

RC_SUBDIRS=	SQL bin installer plugins program skins
CONF_PLUGINS=	acl additional_message_headers database_attachments \
		emoticons help http_authentication jqueryui \
		krb_authentication managesieve new_user_identity \
		newmail_notifier redundant_attachments squirrelmail_usercopy

.for d in ${RC_SUBDIRS}
INSTALLATION_DIRS+=	${RCDIR}/${d}
.endfor
INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR}

OWN_DIRS+=		${PKG_SYSCONFDIR}
OWN_DIRS_PERMS+=	${VARBASE}/log/roundcube \
			${WWW_USER} ${WWW_GROUP} 0750
OWN_DIRS_PERMS+=	${VARBASE}/spool/roundcube \
			${WWW_USER} ${WWW_GROUP} 0750
OWN_DIRS_PERMS+=	${VARBASE}/tmp/roundcube \
			${WWW_USER} ${WWW_GROUP} 0750

CONF_FILES=		${PREFIX}/${EGDIR}/roundcube.conf \
			${PKG_SYSCONFDIR}/roundcube.conf
CONF_FILES+=		${PREFIX}/${EGDIR}/mimetypes.php \
			${PKG_SYSCONFDIR}/mimetypes.php
CONF_FILES_PERMS+=	${PREFIX}/${EGDIR}/config.inc.php \
			${PKG_SYSCONFDIR}/config.inc.php \
			${WWW_USER} ${WWW_GROUP} 0640
CONF_FILES_PERMS+=	${PREFIX}/${EGDIR}/defaults.inc.php \
			${PKG_SYSCONFDIR}/defaults.inc.php \
			${WWW_USER} ${WWW_GROUP} 0640

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

post-extract:
	${CP} ${FILESDIR}/${WWW_CONF_FILE} ${WRKSRC}/roundcube.conf

pre-install:
	cd ${WRKSRC}/plugins && ${RM} -fr enigma password zipdownload

do-install:
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADING ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/.htaccess ${DESTDIR}${PREFIX}/${RCDIR}
	${INSTALL_DATA} ${WRKSRC}/index.php ${DESTDIR}${PREFIX}/${RCDIR}
	${INSTALL_DATA} ${WRKSRC}/robots.txt ${DESTDIR}${PREFIX}/${RCDIR}
.for i in ${RC_SUBDIRS}
	cd ${WRKSRC}/${i} && ${FIND} . -type f \! -name "*.orig" -print | \
		pax -rw ${DESTDIR}${PREFIX}/${RCDIR}/${i}
	${FIND} ${DESTDIR}${PREFIX}/${RCDIR}/${i} -type f | \
		${XARGS} ${CHMOD} ${SHAREMODE}
	${FIND} ${DESTDIR}${PREFIX}/${RCDIR}/${i} -type d | \
		${XARGS} ${CHMOD} ${PKGDIRMODE}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/${RCDIR}/${i}
.endfor
	${INSTALL_DATA} ${WRKSRC}/roundcube.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/roundcube.conf
	${INSTALL_DATA} ${WRKSRC}/config/mimetypes.php \
		${DESTDIR}${PREFIX}/${EGDIR}/mimetypes.php
	${INSTALL_DATA} ${WRKSRC}/config/config.inc.php.sample \
		${DESTDIR}${PREFIX}/${EGDIR}/config.inc.php
	${INSTALL_DATA} ${WRKSRC}/config/defaults.inc.php \
		${DESTDIR}${PREFIX}/${EGDIR}/defaults.inc.php

.include "Makefile.common"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
