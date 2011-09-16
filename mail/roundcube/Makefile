# $NetBSD: Makefile,v 1.36 2011/09/16 05:46:24 obache Exp $

DISTNAME=	roundcubemail-0.5.4-dep
PKGNAME=	${DISTNAME:S/mail-/-/:S/-dep//}
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=roundcubemail/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://roundcube.net/
COMMENT=	Browser-based multilingual IMAP client
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# none
USE_TOOLS+=		pax
NO_BUILD=		yes

INSTALLATION_DIRS=	${RCDIR}/plugins ${RCDIR}/program ${RCDIR}/skins
INSTALLATION_DIRS+=	${EGDIR}/SQL ${DOCDIR} ${RCDIR}/bin

.include "../../mk/bsd.prefs.mk"
.include "../../lang/php/phpversion.mk"

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_IDNA2>=0.1.0:../../net/pear-Net_IDNA2
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_SMTP>=1.4.2:../../net/pear-Net_SMTP
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Mail_Mime>=1.7:../../mail/pear-Mail_Mime
DEPENDS+=	${PHP_PKG_PREFIX}-pear-MDB2>=2.5.0:../../databases/pear-MDB2
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Auth_SASL-[0-9]*:../../mail/pear-Auth_SASL
DEPENDS+=	${PHP_PKG_PREFIX}-dom-[0-9]*:../../textproc/php-dom
DEPENDS+=	${PHP_PKG_PREFIX}-json-[0-9]*:../../textproc/php-json

PKG_SYSCONFSUBDIR=	roundcube

WWW_USER?=		${APACHE_USER}
WWW_GROUP?=		${APACHE_GROUP}

PKG_GROUPS_VARS+=	WWW_GROUP
PKG_USERS_VARS=		WWW_USER
BUILD_DEFS+=		VARBASE WWW_USER WWW_GROUP APACHE_USER APACHE_GROUP

RCDIR=			${PREFIX}/share/roundcube
EGDIR=			${PREFIX}/share/examples/roundcube
DOCDIR=			${PREFIX}/share/doc/roundcube
PAX_DIRS=		plugins program skins installer bin

MESSAGE_SUBST+=		DOCDIR=${DOCDIR} PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
MESSAGE_SUBST+=		VARBASE=${VARBASE} RCDIR=${RCDIR}
FILES_SUBST+=		RCDIR=${RCDIR}

OWN_DIRS+=		${PKG_SYSCONFDIR}
OWN_DIRS_PERMS+=	${VARBASE}/log/roundcube \
			${WWW_USER} ${WWW_GROUP} 0755
OWN_DIRS_PERMS+=	${VARBASE}/tmp/roundcube \
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
REPLACE.php.old=	.*/bin/php
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	bin/*.sh

.include "../../mk/apache.mk"
.include "options.mk"

post-extract:
	${CP} ${FILESDIR}/roundcube.conf ${WRKSRC}/roundcube.conf

pre-install:
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM} -f

do-install:
	${INSTALL_DATA} ${WRKSRC}/roundcube.conf \
		${DESTDIR}${EGDIR}/roundcube.conf
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADING ${DESTDIR}${DOCDIR}

	${INSTALL_DATA} ${WRKSRC}/SQL/*.sql ${DESTDIR}${EGDIR}/SQL/

	${INSTALL_DATA} ${WRKSRC}/.htaccess ${DESTDIR}${RCDIR}/
	${INSTALL_DATA} ${WRKSRC}/index.php ${DESTDIR}${RCDIR}/
	${INSTALL_DATA} ${WRKSRC}/robots.txt ${DESTDIR}${RCDIR}/

	${INSTALL_DATA} ${WRKSRC}/config/mimetypes.php \
		${DESTDIR}${EGDIR}/mimetypes.php
	${INSTALL_DATA} ${WRKSRC}/config/db.inc.php.dist \
		${DESTDIR}${EGDIR}/db.inc.php.dist
	${INSTALL_DATA} ${WRKSRC}/config/main.inc.php.dist \
		${DESTDIR}${EGDIR}/main.inc.php.dist

.for i in ${PAX_DIRS}
	cd ${WRKSRC}/${i} && ${PAX} -rw . ${DESTDIR}${RCDIR}/${i}
	${FIND} ${DESTDIR}${RCDIR}/${i} -type f | \
		${XARGS} ${CHMOD} ${SHAREMODE}
	${FIND} ${DESTDIR}${RCDIR}/${i} -type d | \
		${XARGS} ${CHMOD} ${PKGDIRMODE}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${RCDIR}/${i}
.endfor

.include "../../mk/bsd.pkg.mk"
