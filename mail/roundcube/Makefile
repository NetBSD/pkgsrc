# $NetBSD: Makefile,v 1.93 2020/06/07 22:07:04 taca Exp $

DISTNAME=	roundcubemail-${RC_VERS}
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME:S/mail-/-/:S/-complete//}

MAINTAINER=	taca@NetBSD.org
COMMENT=	Browser-based multilingual IMAP client
LICENSE=	gnu-gpl-v3 AND mit AND gnu-lgpl-v2.1

DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=${PHP_BASE_VERS}:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-exif>=${PHP_BASE_VERS}:../../graphics/php-exif
DEPENDS+=	${PHP_PKG_PREFIX}-intl>=${PHP_BASE_VERS}:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-json>=${PHP_BASE_VERS}:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=${PHP_BASE_VERS}:../../archivers/php-zip

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_Sieve>=1.3.2:../../net/pear-Net_Sieve
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_SMTP>=1.7.1:../../net/pear-Net_SMTP
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_IDNA2>=0.1.1:../../net/pear-Net_IDNA2
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Mail_Mime>=1.10.0:../../mail/pear-Mail_Mime
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Auth_SASL>=1.0.6:../../mail/pear-Auth_SASL

RC_SUBDIRS=	SQL bin installer plugins program skins

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

CONF_FILES+=		${PREFIX}/${EGDIR}/mimetypes.php \
			${PKG_SYSCONFDIR}/mimetypes.php
CONF_FILES_PERMS+=	${PREFIX}/${EGDIR}/config.inc.php \
			${PKG_SYSCONFDIR}/config.inc.php \
			${WWW_USER} ${WWW_GROUP} 0640
CONF_FILES_PERMS+=	${PREFIX}/${EGDIR}/defaults.inc.php \
			${PKG_SYSCONFDIR}/defaults.inc.php \
			${WWW_USER} ${WWW_GROUP} 0640

CONF_PLUGINS=		acl additional_message_headers database_attachments \
			emoticons help http_authentication jqueryui \
			krb_authentication managesieve markasjunk \
			new_user_identity newmail_notifier \
			redundant_attachments squirrelmail_usercopy
RC_DOCS=		CHANGELOG INSTALL LICENSE README.md UPGRADING
REPLACE_PHP=		cleandb.sh decrypt.sh deluser.sh gc.sh \
			indexcontacts.sh initdb.sh installto.sh \
			moduserprefs.sh msgexport.sh msgimport.sh \
			update.sh updatecss.sh updatedb.sh

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*php[^ ]*
REPLACE.php.new=	${PREFIX}/bin/php
.for f in ${REPLACE_PHP}
REPLACE_FILES.php+=	bin/${f}
.endfor

SUBST_CLASSES+=		files
SUBST_STAGE.files=	do-configure
SUBST_MESSAGE.files=	Fixing configuration files.
SUBST_FILES.files=	apache.conf lighttpd.conf nginx.conf
SUBST_FILES.files+=	config/config.inc.php.sample
SUBST_FILES.files+=	program/include/iniset.php
SUBST_FILES.files+=	program/lib/Roundcube/rcube_mime.php
SUBST_VARS.files=	RCDIR VARBASE PKG_EXAMPLES PKG_SYSCONFBASE PKG_SYSCONFDIR
SUBST_VARS.files+=	RCDIR
SUBST_VARS.files+=	VARBASE
SUBST_SED.files+=	-e "s|@PKG_EXAMPLES@|${PREFIX}/share/examples/roundcube|g"
SUBST_VARS.files+=	PKG_SYSCONFBASE
SUBST_VARS.files+=	PKG_SYSCONFDIR

pre-configure:
	${CP} ${FILESDIR}/apache.conf ${WRKSRC}/apache.conf
	${CP} ${FILESDIR}/lighttpd.conf ${WRKSRC}/lighttpd.conf
	${CP} ${FILESDIR}/nginx.conf ${WRKSRC}/nginx.conf

pre-install:
	cd ${WRKSRC}/plugins && ${RM} -fr enigma password zipdownload

do-install:
.for i in ${RC_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${PREFIX}/${DOCDIR}
.endfor
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

.include "Makefile.common"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
