# $NetBSD: Makefile,v 1.9 2008/05/04 16:34:03 adrianp Exp $
#

DISTNAME=	roundcubemail-${VERSION}-dep
PKGNAME=	${DISTNAME:S/mail-${VERSION}-dep/-${VERSION}/}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=roundcubemail/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://roundcube.net/
COMMENT=	Browser-based multilingual IMAP client

USE_LANGUAGES=	# none
NO_BUILD=	yes
VERSION=	0.1.1

.include "../../mk/bsd.prefs.mk"
.include "../../lang/php/phpversion.mk"

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_SMTP>=1.2.10:../../net/pear-Net_SMTP
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Mail_Mime>=1.3:../../mail/pear-Mail_Mime
DEPENDS+=	${PHP_PKG_PREFIX}-pear-MDB2>=2.4.1:../../databases/pear-MDB2
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Auth_SASL-[0-9]*:../../mail/pear-Auth_SASL

PKG_SYSCONFSUBDIR?=	roundcube

WWW_USER?=		${APACHE_USER}
WWW_GROUP?=		${APACHE_GROUP}

PKG_GROUPS_VARS+=	WWW_GROUP
PKG_USERS_VARS+=	WWW_USER
BUILD_DEFS+=		VARBASE WWW_USER WWW_GROUP APACHE_USER APACHE_GROUP

RCDIR=			${PREFIX}/share/roundcube
EGDIR=			${PREFIX}/share/examples/roundcube
DOCDIR=			${PREFIX}/share/doc/roundcube
PAX_DIRS=		program skins installer

MESSAGE_SUBST+=		DOCDIR=${DOCDIR:Q} PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}
MESSAGE_SUBST+=		VARBASE=${VARBASE:Q} RCDIR=${RCDIR:Q}
FILES_SUBST+=		RCDIR=${RCDIR:Q}

OWN_DIRS_PERMS+=	${VARBASE}/log/roundcube \
			${WWW_USER} ${WWW_GROUP} 0755
OWN_DIRS_PERMS+=	${VARBASE}/tmp/roundcube \
			${WWW_USER} ${WWW_GROUP} 0755

CONF_FILES=		${EGDIR}/roundcube.conf \
			${PKG_SYSCONFDIR}/roundcube.conf

SUBST_CLASSES+=		files
SUBST_STAGE.files=	do-configure
SUBST_FILES.files=	roundcube.conf
SUBST_FILES.files+=	config/main.inc.php.dist
SUBST_SED.files=	-e "s|@RCDIR@|${RCDIR}|g"
SUBST_SED.files+=	-e "s|@VARBASE@|${VARBASE}|g"
SUBST_MESSAGE.files=	Fixing configuration files.

INSTALLATION_DIRS=	${RCDIR}/program ${RCDIR}/skins ${EGDIR}/SQL ${DOCDIR}

.include "../../mk/apache.mk"
.include "options.mk"

post-extract:
	${CP} ${FILESDIR}/roundcube.conf ${WRKSRC}/roundcube.conf

pre-install:
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM} -f

do-install:
	${INSTALL_DATA_DIR} ${RCDIR}/config
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
	${INSTALL_DATA} ${WRKSRC}/config/db.inc.php.dist \
		${RCDIR}/config/db.inc.php.dist
	${INSTALL_DATA} ${WRKSRC}/config/main.inc.php.dist \
		${RCDIR}/config/main.inc.php.dist

	${CHMOD} ${PKGDIRMODE} ${RCDIR}/config
	${CHOWN} ${WWW_USER}:${WWW_GROUP} ${RCDIR}/config
	${CHOWN} ${WWW_USER}:${WWW_GROUP} ${RCDIR}/config/*.dist

.	for i in ${PAX_DIRS}
		cd ${WRKSRC}/${i} && ${PAX} -rw . ${RCDIR}/${i}
		${FIND} ${RCDIR}/${i} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
		${FIND} ${RCDIR}/${i} -type d | ${XARGS} ${CHMOD} ${PKGDIRMODE}
		${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${RCDIR}/${i}
.	endfor

.include "../../mk/bsd.pkg.mk"
