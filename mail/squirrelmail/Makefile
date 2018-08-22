# $NetBSD: Makefile,v 1.135 2018/08/22 09:45:34 wiz Exp $

DISTNAME=	squirrelmail-webmail-1.4.23pre14764
PKGNAME=	${DISTNAME:S/-webmail//}
PKGREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	PHP webmail package
LICENSE=	gnu-gpl-v2

CONFLICTS=	sq-attachment-handlers-[0-9]*
CONFLICTS+=	sq-squirrelspell-[0-9]*
CONFLICTS+=	ja-squirrelspell-[0-9]*
CONFLICTS+=	ja-squirrelmail-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-gettext>=4.3.3:../../devel/php-gettext

USE_LANGUAGES=	# empty
NO_BUILD=	yes
USE_TOOLS+=	pax perl:run
REPLACE_PERL+=	config/conf.pl

PKG_GROUPS_VARS+=	APACHE_GROUP
PKG_USERS_VARS+=	APACHE_USER
BUILD_DEFS+=		VARBASE

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	httpd
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

EGDIR=			share/examples/squirrelmail
SMDIR=			share/squirrelmail
DATADIR=		${VARBASE}/spool/squirrelmail
ATTACHMENTS_DIR=	${DATADIR}/attachments
USER_PREFS_DIR=		${DATADIR}/data

MESSAGE_SUBST+=		SMDIR=${PREFIX}/${SMDIR}
FILES_SUBST+=		SMDIR=${PREFIX}/${SMDIR}

CONF_FILES=		${SMDIR}/config/config_default.php \
			${SMDIR}/config/config.php
CONF_FILES+=		${SMDIR}/data/default_pref \
			${DATADIR}/data/default_pref
CONF_FILES+=		${EGDIR}/squirrelmail.conf \
			${PKG_SYSCONFDIR}/squirrelmail.conf
CONF_FILES+=		${EGDIR}/data/.htaccess ${DATADIR}/data/.htaccess
CONF_FILES+=		${EGDIR}/data/index.php ${DATADIR}/data/index.php
CONF_FILES+=		${EGDIR}/data/.htaccess ${USER_PREFS_DIR}/.htaccess
CONF_FILES+=		${EGDIR}/data/index.php ${USER_PREFS_DIR}/index.php

REQD_DIRS+=		${SMDIR} ${SMDIR}/config

OWN_DIRS+=		${DATADIR}
OWN_DIRS_PERMS+=	${ATTACHMENTS_DIR} ${REAL_ROOT_USER} ${APACHE_GROUP} 730
OWN_DIRS_PERMS+=	${USER_PREFS_DIR} ${APACHE_USER} ${APACHE_GROUP} 755

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/squirrelmail.conf.dist
SUBST_FILES.paths+=	config/config_default.php
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@ATTACHMENTS_DIR@,${ATTACHMENTS_DIR},g'
SUBST_SED.paths+=	-e 's,@USER_PREFS_DIR@,${USER_PREFS_DIR},g'
SUBST_SED.paths+=	-e 's,@SMDIR@,${PREFIX}/${SMDIR},g'
SUBST_STAGE.paths=	pre-configure

DATA_FILES=		.htaccess index.php
INSTALLATION_DIRS=	${PKGMANDIR}/man8 ${EGDIR}/data ${SMDIR}

post-extract:
	${CP} ${FILESDIR}/squirrelmail.conf.dist \
		${WRKDIR}/squirrelmail.conf.dist
	${CP} -p ${WRKSRC}/contrib/conf.pl.8 ${WRKDIR}/squirrelmail-conf.pl.8

pre-install:
	${FIND} ${WRKSRC} \( -name '*.orig*' -o -name '.cvsignore' \) \
		-exec rm -f {} \;
	${FIND} ${WRKSRC} -type d -exec chmod ${PKGDIRMODE} {} \;
	${FIND} ${WRKSRC} -type f -exec chmod ${SHAREMODE} {} \;
	${CHMOD} 0555 ${WRKSRC}/config/conf.pl
	${RM} -f ${WRKSRC}/contrib/conf.pl.8

do-install:
	${INSTALL_DATA} ${WRKDIR}/squirrelmail.conf.dist \
		${DESTDIR}${PREFIX}/${EGDIR}/squirrelmail.conf
.for f in ${DATA_FILES}
	${INSTALL_DATA} ${WRKSRC}/data/${f} ${DESTDIR}${PREFIX}/${EGDIR}/data
.endfor
	cd ${WRKSRC}; pax -rw -pp . ${DESTDIR}${PREFIX}/${SMDIR}
	${INSTALL_DATA} ${WRKDIR}/squirrelmail-conf.pl.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
