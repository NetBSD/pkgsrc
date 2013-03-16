# $NetBSD: Makefile,v 1.52 2013/03/16 07:21:21 obache Exp $

DISTNAME=	roundcubemail-0.8.5-dep
PKGNAME=	${DISTNAME:S/mail-/-/:S/-dep//}
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=roundcubemail/}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://roundcube.net/
COMMENT=	Browser-based multilingual IMAP client
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_SMTP>=1.4.2:../../net/pear-Net_SMTP
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Mail_Mime>=1.8.1:../../mail/pear-Mail_Mime
DEPENDS+=	${PHP_PKG_PREFIX}-pear-MDB2>=2.5.0:../../databases/pear-MDB2
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Auth_SASL>=1.0.3:../../mail/pear-Auth_SASL
DEPENDS+=	${PHP_PKG_PREFIX}-dom-[0-9]*:../../textproc/php-dom
DEPENDS+=	${PHP_PKG_PREFIX}-json-[0-9]*:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_IDNA2>=0.1.1:../../net/pear-Net_IDNA2

USE_LANGUAGES=		# none
USE_TOOLS+=		pax
NO_BUILD=		yes

INSTALLATION_DIRS=	${RCDIR}/plugins ${RCDIR}/program ${RCDIR}/skins
INSTALLATION_DIRS+=	${RCDIR}/bin ${RCDIR}/SQL ${DOCDIR} ${EGDIR}

.include "../../lang/php/phpversion.mk"

PKG_SYSCONFSUBDIR?=	roundcube

WWW_USER?=		${APACHE_USER}
WWW_GROUP?=		${APACHE_GROUP}

PKG_GROUPS_VARS+=	WWW_GROUP
PKG_USERS_VARS=		WWW_USER
BUILD_DEFS+=		VARBASE WWW_USER WWW_GROUP APACHE_USER APACHE_GROUP

RCDIR=			${PREFIX}/share/roundcube
EGDIR=			${PREFIX}/share/examples/roundcube
DOCDIR=			${PREFIX}/share/doc/roundcube
PAX_DIRS=		plugins program skins installer

CONF_PLUGINS=		acl additional_message_headers enigma help \
			jqueryui managesieve newmail_notifier password \
			redundant_attachments squirrelmail_usercopy

MESSAGE_SUBST+=		DOCDIR=${DOCDIR} PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
MESSAGE_SUBST+=		VARBASE=${VARBASE} RCDIR=${RCDIR}
FILES_SUBST+=		RCDIR=${RCDIR}

OWN_DIRS+=		${PKG_SYSCONFDIR}
OWN_DIRS_PERMS+=	${VARBASE}/log/roundcube \
			${WWW_USER} ${WWW_GROUP} 0755
OWN_DIRS_PERMS+=	${VARBASE}/spool/roundcube \
			${WWW_USER} ${WWW_GROUP} 0755

CONF_FILES=		${EGDIR}/roundcube.conf \
			${PKG_SYSCONFDIR}/roundcube.conf
CONF_FILES+=		${EGDIR}/mimetypes.php \
			${PKG_SYSCONFDIR}/mimetypes.php
CONF_FILES_PERMS+=	${EGDIR}/db.inc.php.dist \
			${PKG_SYSCONFDIR}/db.inc.php \
			${WWW_USER} ${WWW_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/main.inc.php.dist \
			${PKG_SYSCONFDIR}/main.inc.php \
			${WWW_USER} ${WWW_GROUP} 0640

.for f in ${CONF_PLUGINS}
CONF_FILES_PERMS+=	${EGDIR}/plugins/${f}/config.inc.php \
			${RCDIR}/plugins/${f}/config.inc.php \
			${WWW_USER} ${WWW_GROUP} 0640
.endfor

SUBST_CLASSES+=		files
SUBST_STAGE.files=	do-configure
SUBST_FILES.files=	roundcube.conf
SUBST_FILES.files+=	config/main.inc.php.dist
SUBST_FILES.files+=	installer/index.php
SUBST_FILES.files+=	program/include/iniset.php
SUBST_SED.files=	-e "s|@RCDIR@|${RCDIR}|g"
SUBST_SED.files+=	-e "s|@VARBASE@|${VARBASE}|g"
SUBST_SED.files+=	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"
SUBST_MESSAGE.files=	Fixing configuration files.

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	/usr/bin/env php
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	bin/*.sh

.include "../../mk/apache.mk"
.include "options.mk"

post-extract:
	${CP} ${FILESDIR}/roundcube.conf ${WRKSRC}/roundcube.conf

pre-install:
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM} -f

do-install:
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADING ${DESTDIR}${DOCDIR}

	${INSTALL_DATA} ${WRKSRC}/.htaccess ${DESTDIR}${RCDIR}/
	${INSTALL_DATA} ${WRKSRC}/index.php ${DESTDIR}${RCDIR}/
	${INSTALL_DATA} ${WRKSRC}/robots.txt ${DESTDIR}${RCDIR}/
	${INSTALL_DATA} ${WRKSRC}/SQL/*.sql ${DESTDIR}${RCDIR}/SQL/

	${INSTALL_DATA} ${WRKSRC}/roundcube.conf \
		${DESTDIR}${EGDIR}/roundcube.conf
	${INSTALL_DATA} ${WRKSRC}/config/mimetypes.php \
		${DESTDIR}${EGDIR}/mimetypes.php
	${INSTALL_DATA} ${WRKSRC}/config/db.inc.php.dist \
		${DESTDIR}${EGDIR}/db.inc.php.dist
	${INSTALL_DATA} ${WRKSRC}/config/main.inc.php.dist \
		${DESTDIR}${EGDIR}/main.inc.php.dist

	${INSTALL_SCRIPT} ${WRKSRC}/bin/*.sh ${DESTDIR}${RCDIR}/bin/

.for i in ${PAX_DIRS}
	${INSTALL_DATA_DIR} ${DESTDIR}${RCDIR}/${i}
	cd ${WRKSRC}/${i} && ${PAX} -rw . ${DESTDIR}${RCDIR}/${i}
	${FIND} ${DESTDIR}${RCDIR}/${i} -type f | \
		${XARGS} ${CHMOD} ${SHAREMODE}
	${FIND} ${DESTDIR}${RCDIR}/${i} -type d | \
		${XARGS} ${CHMOD} ${PKGDIRMODE}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${RCDIR}/${i}
.endfor

.for f in ${CONF_PLUGINS}
	${MKDIR} ${DESTDIR}${EGDIR}/plugins/${f}
	test -f ${DESTDIR}${EGDIR}/plugins/${f}/config.inc.php || \
		${MV} ${DESTDIR}${RCDIR}/plugins/${f}/config.inc.php.dist \
			${DESTDIR}${EGDIR}/plugins/${f}/config.inc.php
.endfor

.include "../../mk/bsd.pkg.mk"
