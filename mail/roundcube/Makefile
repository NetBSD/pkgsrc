# $NetBSD: Makefile,v 1.88.10.1 2018/05/19 09:18:37 spz Exp $

DISTNAME=	roundcubemail-${RC_VERS}
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME:S/mail-/-/}

MAINTAINER=	taca@NetBSD.org
COMMENT=	Browser-based multilingual IMAP client
LICENSE=	gnu-gpl-v3 AND mit AND gnu-lgpl-v2.1

# JavaScript dependencies from bin/install-jsdeps.sh
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	jquery-3.2.1.min.js
DISTFILES+=	jstz.min.js
DISTFILES+=	publickey.js
DISTFILES+=	tinymce_4.5.8.zip
DISTFILES+=	tinymce_languages.zip
DISTFILES+=	codemirror-5.21.0.zip

DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=${PHP_BASE_VERS}:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-exif>=${PHP_BASE_VERS}:../../graphics/php-exif
DEPENDS+=	${PHP_PKG_PREFIX}-intl>=${PHP_BASE_VERS}:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-json>=${PHP_BASE_VERS}:../../textproc/php-json

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_Sieve>=1.3.2:../../net/pear-Net_Sieve
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_SMTP>=1.7.1:../../net/pear-Net_SMTP
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_IDNA2>=0.1.1:../../net/pear-Net_IDNA2
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Mail_Mime>=1.10.0:../../mail/pear-Mail_Mime
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Auth_SASL>=1.0.6:../../mail/pear-Auth_SASL

RC_SUBDIRS=	SQL bin plugins program skins
TMCE_SUBDIRS=	langs plugins skins themes
CM_SUBDIRS=	lib mode/sieve addon/selection
CONF_PLUGINS=	acl additional_message_headers database_attachments \
		emoticons help http_authentication jqueryui \
		krb_authentication managesieve new_user_identity \
		newmail_notifier redundant_attachments squirrelmail_usercopy

.for d in ${RC_SUBDIRS}
INSTALLATION_DIRS+=	${RCDIR}/${d}
.endfor
.for d in ${TMCE_SUBDIRS}
INSTALLATION_DIRS+=	${RCDIR}/program/js/tinymce/${d}
.endfor
.for d in ${CM_SUBDIRS}
INSTALLATION_DIRS+=	${RCDIR}/plugins/managesieve/codemirror/${d}
.endfor
INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR}


OWN_DIRS+=		${PKG_SYSCONFDIR}
OWN_DIRS_PERMS+=	${VARBASE}/log/roundcube \
			${WWW_USER} ${WWW_GROUP} 0750
OWN_DIRS_PERMS+=	${VARBASE}/spool/roundcube \
			${WWW_USER} ${WWW_GROUP} 0750
OWN_DIRS_PERMS+=	${VARBASE}/tmp/roundcube \
			${WWW_USER} ${WWW_GROUP} 0750

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
SUBST_FILES.files=	apache.conf lighttpd.conf nginx.conf
SUBST_FILES.files+=	config/config.inc.php.sample
SUBST_FILES.files+=	program/include/iniset.php
SUBST_FILES.files+=	program/lib/Roundcube/rcube_mime.php
SUBST_VARS.files=	RCDIR VARBASE PKG_EXAMPLES PKG_SYSCONFBASE PKG_SYSCONFDIR
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
	${CP} ${FILESDIR}/apache.conf ${WRKSRC}/apache.conf
	${CP} ${FILESDIR}/lighttpd.conf ${WRKSRC}/lighttpd.conf
	${CP} ${FILESDIR}/nginx.conf ${WRKSRC}/nginx.conf

pre-install:
	cd ${WRKSRC}/plugins && ${RM} -fr enigma password zipdownload

do-install:
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADING ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/.htaccess ${DESTDIR}${PREFIX}/${RCDIR}
	${INSTALL_DATA} ${WRKSRC}/index.php ${DESTDIR}${PREFIX}/${RCDIR}
.for i in ${RC_SUBDIRS}
	cd ${WRKSRC}/${i} && ${FIND} . -type f \! -name "*.orig" -print | \
		pax -rw ${DESTDIR}${PREFIX}/${RCDIR}/${i}
	${FIND} ${DESTDIR}${PREFIX}/${RCDIR}/${i} -type f | \
		${XARGS} ${CHMOD} ${SHAREMODE}
	${FIND} ${DESTDIR}${PREFIX}/${RCDIR}/${i} -type d | \
		${XARGS} ${CHMOD} ${PKGDIRMODE}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/${RCDIR}/${i}
.endfor
	${INSTALL_DATA} ${WRKSRC}/apache.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/apache.conf
	${INSTALL_DATA} ${WRKSRC}/lighttpd.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/lighttpd.conf
	${INSTALL_DATA} ${WRKSRC}/nginx.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/nginx.conf
	${INSTALL_DATA} ${WRKSRC}/config/mimetypes.php \
		${DESTDIR}${PREFIX}/${EGDIR}/mimetypes.php
	${INSTALL_DATA} ${WRKSRC}/config/config.inc.php.sample \
		${DESTDIR}${PREFIX}/${EGDIR}/config.inc.php
	${INSTALL_DATA} ${WRKSRC}/config/defaults.inc.php \
		${DESTDIR}${PREFIX}/${EGDIR}/defaults.inc.php
	${INSTALL_DATA} ${WRKDIR}/jquery-3.2.1.min.js \
	  	${DESTDIR}${PREFIX}/${RCDIR}/program/js/jquery.min.js
	${INSTALL_DATA} ${WRKDIR}/jstz.min.js \
	  	${DESTDIR}${PREFIX}/${RCDIR}/program/js/jstz.min.js
	${INSTALL_DATA} ${WRKDIR}/publickey.js \
	  	${DESTDIR}${PREFIX}/${RCDIR}/program/js/publickey.js
.for i in ${TMCE_SUBDIRS}
	cd ${WRKDIR}/tinymce/js/tinymce/${i} && ${FIND} . -type f -print | \
	  	pax -rw ${DESTDIR}${PREFIX}/${RCDIR}/program/js/tinymce/${i}
	${FIND} ${DESTDIR}${PREFIX}/${RCDIR}/program/js/tinymce/${i} -type f | \
	  	${XARGS} ${CHMOD} ${SHAREMODE}
	${FIND} ${DESTDIR}${PREFIX}/${RCDIR}/program/js/tinymce/${i} -type d | \
	  	${XARGS} ${CHMOD} ${PKGDIRMODE}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/${RCDIR}/program/js/tinymce/${i}
.endfor
	${INSTALL_DATA} ${WRKDIR}/tinymce/js/tinymce/tinymce.min.js \
	  ${DESTDIR}${PREFIX}/${RCDIR}/program/js/tinymce/tinymce.min.js
	cd ${WRKDIR}/langs && ${FIND} . -type f -print | \
	  	pax -rw ${DESTDIR}${PREFIX}/${RCDIR}/program/js/tinymce/langs
	${FIND} ${DESTDIR}${PREFIX}/${RCDIR}/program/js/tinymce/langs -type f | \
	  	${XARGS} ${CHMOD} ${SHAREMODE}
	${FIND} ${DESTDIR}${PREFIX}/${RCDIR}/program/js/tinymce/langs -type d | \
	  	${XARGS} ${CHMOD} ${PKGDIRMODE}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/${RCDIR}/program/js/tinymce/langs
.for i in ${CM_SUBDIRS}
	cd ${WRKDIR}/codemirror-5.21.0/${i} && ${FIND} . -type f -print | \
	  	pax -rw ${DESTDIR}${PREFIX}/${RCDIR}/plugins/managesieve/codemirror/${i}
	${FIND} ${DESTDIR}${PREFIX}/${RCDIR}/plugins/managesieve/codemirror/${i} -type f | \
	  	${XARGS} ${CHMOD} ${SHAREMODE}
	${FIND} ${DESTDIR}${PREFIX}/${RCDIR}/plugins/managesieve/codemirror/${i} -type d | \
	  	${XARGS} ${CHMOD} ${PKGDIRMODE}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/${RCDIR}/plugins/managesieve/codemirror/${i}
.endfor

.include "Makefile.common"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
