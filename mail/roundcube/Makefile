# $NetBSD: Makefile,v 1.16 2009/02/28 17:35:04 adrianp Exp $
#

DISTNAME=	roundcubemail-${RCVERSION}-dep
PKGREVISION=	1
PKGNAME=	${DISTNAME:S/mail-${RCVERSION}-dep/-${VERSION}/}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=roundcubemail/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://roundcube.net/
COMMENT=	Browser-based multilingual IMAP client

USE_TOOLS+=	pax
USE_LANGUAGES=	# none
NO_BUILD=	yes
RCVERSION=	0.2-stable
VERSION=	${RCVERSION:S/-//}

.include "../../mk/bsd.prefs.mk"
.include "../../lang/php/phpversion.mk"

DEPENDS+=	php5-dom-5.2.*:../../textproc/php5-dom
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_SMTP>=1.2.10:../../net/pear-Net_SMTP
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Mail_Mime>=1.3:../../mail/pear-Mail_Mime
DEPENDS+=	${PHP_PKG_PREFIX}-pear-MDB2>=2.4.1:../../databases/pear-MDB2
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Auth_SASL-[0-9]*:../../mail/pear-Auth_SASL

.if ${PKG_PHP_VERSION} == "4"
DEPENDS+=	${PHP_PKG_PREFIX}-domxml>=4.3.3:../../textproc/php4-domxml
.elif ${PKG_PHP_VERSION} == "5"
DEPENDS+=	${PHP_PKG_PREFIX}-dom-[0-9]*:../../textproc/php5-dom
.endif

PKG_SYSCONFSUBDIR?=	roundcube

WWW_USER?=		${APACHE_USER}
WWW_GROUP?=		${APACHE_GROUP}

PKG_GROUPS_VARS+=	WWW_GROUP
PKG_USERS_VARS+=	WWW_USER
BUILD_DEFS+=		VARBASE WWW_USER WWW_GROUP APACHE_USER APACHE_GROUP

RCDIR=			${PREFIX}/share/roundcube
EGDIR=			${PREFIX}/share/examples/roundcube
DOCDIR=			${PREFIX}/share/doc/roundcube
PAX_DIRS=		program skins installer bin

MESSAGE_SUBST+=		DOCDIR=${DOCDIR:Q} PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}
MESSAGE_SUBST+=		VARBASE=${VARBASE:Q} RCDIR=${RCDIR:Q}
FILES_SUBST+=		RCDIR=${RCDIR:Q}

OWN_DIRS+=		${PKG_SYSCONFDIR}
OWN_DIRS_PERMS+=	${VARBASE}/log/roundcube \
			${WWW_USER} ${WWW_GROUP} 0755
OWN_DIRS_PERMS+=	${VARBASE}/tmp/roundcube \
			${WWW_USER} ${WWW_GROUP} 0755

CONF_FILES=		${EGDIR}/roundcube.conf \
			${PKG_SYSCONFDIR}/roundcube.conf
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

EMPTY_DIRS=	plugins/cleanup plugins/emotions/images \
		plugins/emotions/jscripts plugins/media/images \
		plugins/media/jscripts plugins/nonbreaking/images \
		plugins/nonbreaking/langs plugins/searchreplace/images \
		plugins/searchreplace/jscripts plugins/spellchecker/images \
		plugins/spellchecker/langs plugins/table/images \
		plugins/table/jscripts plugins/visualchars/images \
		plugins/visualchars/langs themes/advanced/css \
		themes/advanced/docs/en/images themes/advanced/images/xp \
		themes/advanced/jscripts themes/advanced/docs/en \
		themes/advanced/images themes/advanced/docs

INSTALLATION_DIRS=	${RCDIR}/program ${RCDIR}/skins ${EGDIR}/SQL ${DOCDIR}
INSTALLATION_DIRS+=	${RCDIR}/bin

.include "../../mk/apache.mk"
.include "options.mk"

post-extract:
	${CP} ${FILESDIR}/roundcube.conf ${WRKSRC}/roundcube.conf

pre-install:
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM} -f

.	for d in ${EMPTY_DIRS}
		cd ${WRKSRC}/program/js/tiny_mce && rmdir ${d}
.	endfor

do-install:
	${INSTALL_DATA} ${WRKSRC}/roundcube.conf ${EGDIR}/roundcube.conf
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADING ${DOCDIR}

	${INSTALL_DATA} ${WRKSRC}/SQL/*.sql ${EGDIR}/SQL/

	${INSTALL_DATA} ${WRKSRC}/.htaccess ${RCDIR}/
	${INSTALL_DATA} ${WRKSRC}/index.php ${RCDIR}/
	${INSTALL_DATA} ${WRKSRC}/robots.txt ${RCDIR}/

	${INSTALL_DATA} ${WRKSRC}/config/db.inc.php.dist \
		${EGDIR}/db.inc.php.dist
	${INSTALL_DATA} ${WRKSRC}/config/main.inc.php.dist \
		${EGDIR}/main.inc.php.dist

.	for i in ${PAX_DIRS}
		cd ${WRKSRC}/${i} && ${PAX} -rw . ${RCDIR}/${i}
		${FIND} ${RCDIR}/${i} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
		${FIND} ${RCDIR}/${i} -type d | ${XARGS} ${CHMOD} ${PKGDIRMODE}
		${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${RCDIR}/${i}
.	endfor

.include "../../mk/bsd.pkg.mk"
