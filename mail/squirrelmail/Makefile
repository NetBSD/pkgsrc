# $NetBSD: Makefile,v 1.151 2026/01/20 07:29:01 wiz Exp $

DISTNAME=	squirrelmail-webmail-1.4.23pre15037
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME:S/-webmail//}
PKGREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://www.squirrelmail.org/
COMMENT=	PHP webmail package
LICENSE=	gnu-gpl-v2

CONFLICTS=	sq-attachment-handlers-[0-9]*
CONFLICTS+=	sq-squirrelspell-[0-9]*
CONFLICTS+=	ja-squirrelspell-[0-9]*
CONFLICTS+=	ja-squirrelmail-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-gettext>=${PHP_BASE_VERS}:../../devel/php-gettext

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

ATTACHMENTS_DIR=	${DATADIR}/attachments
USER_PREFS_DIR=		${DATADIR}/data

SM_CONF_FILES=		config.php config_local.php
SM_DATA_FILES=		.htaccess default_pref index.php
SM_USER_PREFS_FILES=	.htaccess index.php

CONF_FILES+=		${EGDIR}/squirrelmail.conf \
			${PKG_SYSCONFDIR}/squirrelmail.conf
.for f in ${SM_CONF_FILES}
CONF_FILES+=		${EGDIR}/${f} ${SMDIR}/config/${f}
.endfor
.for f in ${SM_DATA_FILES}
CONF_FILES+=		${EGDIR}/data/${f} ${DATADIR}/data/${f}
.endfor
.for f in ${SM_USER_PREFS_FILES}
CONF_FILES+=		${EGDIR}/data/${f} ${USER_PREFS_DIR}/${f}
.endfor

REQD_DIRS+=		${SMDIR} ${SMDIR}/config

OWN_DIRS+=		${DATADIR}
OWN_DIRS_PERMS+=	${ATTACHMENTS_DIR} ${REAL_ROOT_USER} ${APACHE_GROUP} 730
OWN_DIRS_PERMS+=	${USER_PREFS_DIR} ${APACHE_USER} ${APACHE_GROUP} 755

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/squirrelmail.conf.dist
SUBST_FILES.paths+=	config/config_default.php
SUBST_VARS.paths=	PREFIX
SUBST_VARS.paths+=	ATTACHMENTS_DIR
SUBST_VARS.paths+=	USER_PREFS_DIR
SUBST_SED.paths+=	-e 's,@SMDIR@,${PREFIX}/${SMDIR},g'
SUBST_STAGE.paths=	pre-configure

INSTALLATION_DIRS=	${PKGMANDIR}/man8 ${EGDIR}/data ${SMDIR}

post-extract:
	${CP} ${FILESDIR}/squirrelmail.conf.dist \
		${WRKDIR}/squirrelmail.conf.dist
	${CP} -p ${WRKSRC}/contrib/conf.pl.8 ${WRKDIR}/squirrelmail-conf.pl.8

pre-install:
	${MV} ${WRKSRC}/config/config_default.php ${WRKDIR}/config.php
	${MV} ${WRKSRC}/config/config_local.php ${WRKDIR}
.for f in ${SM_DATA_FILES}
	${MV} ${WRKSRC}/data/${f} ${WRKDIR}
.endfor
	${FIND} ${WRKSRC} \( -name '*.orig*' -o -name '.cvsignore' \) \
		-exec rm -f {} \;
	${FIND} ${WRKSRC} -type d -exec chmod ${PKGDIRMODE} {} \;
	${FIND} ${WRKSRC} -type f -exec chmod ${SHAREMODE} {} \;
	${CHMOD} 0555 ${WRKSRC}/config/conf.pl
	${RM} -f ${WRKSRC}/contrib/conf.pl.8

do-install:
	${INSTALL_DATA} ${WRKDIR}/squirrelmail.conf.dist \
		${DESTDIR}${PREFIX}/${EGDIR}/squirrelmail.conf
.for f in ${SM_CONF_FILES}
	${INSTALL_DATA} ${WRKDIR}/${f} ${DESTDIR}${PREFIX}/${EGDIR}
.endfor
.for f in ${SM_DATA_FILES}
	${INSTALL_DATA} ${WRKDIR}/${f} ${DESTDIR}${PREFIX}/${EGDIR}/data
.endfor
	cd ${WRKSRC}; pax -rw -pp . ${DESTDIR}${PREFIX}/${SMDIR}
	${INSTALL_DATA} ${WRKDIR}/squirrelmail-conf.pl.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mail/squirrelmail/squirrelmail.mk"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
