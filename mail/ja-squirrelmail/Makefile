# $NetBSD: Makefile,v 1.24 2006/02/03 10:26:44 martti Exp $

DISTNAME=	squirrelmail-1.4.5
PKGNAME=	ja-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squirrelmail/}
EXTRACT_SUFX=	.tar.bz2

PATCH_SITES=	http://www.yamaai-tech.com/~masato/Download/
PATCHFILES=	squirrelmail-1.4.5-ja-20050714-patch.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.squirrelmail.jp/
COMMENT=	PHP webmail package with Japanese localization

CONFLICTS=	sq-attachment-handlers-[0-9]*
CONFLICTS+=	sq-squirrelspell-[0-9]*
CONFLICTS+=	squirrelmail-[0-9]*

DEPENDS+=	php-gettext>=4.3.3:../../devel/php-gettext
DEPENDS+=	php-mbstring>=4.3.3:../../misc/php-mbstring

USE_LANGUAGES=	# empty
NO_BUILD=	yes
USE_TOOLS+=	perl:run
REPLACE_PERL=	config/conf.pl config/ri_once.pl

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	httpd
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/squirrelmail
SMDIR=			${PREFIX}/share/squirrelmail
DATADIR=		${VARBASE}/spool/squirrelmail
ATTACHMENTS_DIR=	${DATADIR}/attachments
USER_PREFS_DIR=		${DATADIR}/data

MESSAGE_SUBST+=		SMDIR=${SMDIR}
FILES_SUBST+=		SMDIR=${SMDIR:Q}

CONF_FILES=	${SMDIR}/config/config_default.php ${SMDIR}/config/config.php
CONF_FILES+=	${SMDIR}/data/default_pref ${DATADIR}/data/default_pref
CONF_FILES+=	${EGDIR}/squirrelmail.conf ${PKG_SYSCONFDIR}/squirrelmail.conf

REQD_DIRS=		${SMDIR} ${SMDIR}/config

OWN_DIRS=		${DATADIR}
OWN_DIRS_PERMS=		${ATTACHMENTS_DIR} ${ROOT_USER} ${APACHE_GROUP} 730
OWN_DIRS_PERMS+=	${USER_PREFS_DIR} ${APACHE_USER} ${APACHE_GROUP} 755

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/squirrelmail.conf.dist config/config_default.php
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@ATTACHMENTS_DIR@,${ATTACHMENTS_DIR},g'
SUBST_SED.paths+=	-e 's,@USER_PREFS_DIR@,${USER_PREFS_DIR},g'
SUBST_SED.paths+=	-e 's,@SMDIR@,${SMDIR},g'
SUBST_STAGE.paths=	post-patch

post-extract:
	${CP} ${FILESDIR}/squirrelmail.conf.dist ${WRKDIR}/squirrelmail.conf.dist

pre-configure:
	${FIND} ${WRKSRC} \( -name "*.orig*" -o -name ".cvsignore" \) -exec ${RM} -f {} \;

do-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${SMDIR}
	${INSTALL_DATA} ${WRKDIR}/squirrelmail.conf.dist ${EGDIR}/squirrelmail.conf
	${CP} -R ${WRKSRC}/* ${SMDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${SMDIR}
	${FIND} ${SMDIR} -type d -print -exec ${CHMOD} ${PKGDIRMODE} {} \;
	${FIND} ${SMDIR} -type f -print -exec ${CHMOD} ${SHAREMODE} {} \;
	${CHMOD} a+x ${SMDIR}/config/conf.pl
	${INSTALL_DATA} ${WRKSRC}/data/index.php ${USER_PREFS_DIR}/
	${INSTALL_DATA} ${WRKSRC}/data/.htaccess ${USER_PREFS_DIR}/

.include "../../mk/bsd.pkg.mk"
