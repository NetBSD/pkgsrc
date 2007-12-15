# $NetBSD: Makefile,v 1.97 2007/12/15 13:58:11 taca Exp $

DISTNAME=	squirrelmail-1.4.13
PKGREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squirrelmail/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	PHP webmail package
#LICENSE=	gnu-gpl-v2

CONFLICTS=	sq-attachment-handlers-[0-9]*
CONFLICTS+=	sq-squirrelspell-[0-9]*
CONFLICTS+=	ja-squirrelspell-[0-9]*
CONFLICTS+=	ja-squirrelmail-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-gettext>=4.3.3:../../devel/php-gettext

USE_LANGUAGES=	# empty
NO_BUILD=	yes
USE_TOOLS+=	perl:run
REPLACE_PERL+=	config/conf.pl

PKG_GROUPS_VARS+=	APACHE_GROUP
PKG_USERS_VARS+=	APACHE_USER
BUILD_DEFS+=		VARBASE

.include "options.mk"

PKG_SYSCONFSUBDIR?=	httpd
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/squirrelmail
SMDIR=			${PREFIX}/share/squirrelmail
DATADIR=		${VARBASE}/spool/squirrelmail
ATTACHMENTS_DIR=	${DATADIR}/attachments
USER_PREFS_DIR=		${DATADIR}/data

MESSAGE_SUBST+=		SMDIR=${SMDIR}
FILES_SUBST+=		SMDIR=${SMDIR}

CONF_FILES=		${SMDIR}/config/config_default.php \
			${SMDIR}/config/config.php
CONF_FILES+=		${SMDIR}/data/default_pref \
			${DATADIR}/data/default_pref
CONF_FILES+=		${EGDIR}/squirrelmail.conf \
			${PKG_SYSCONFDIR}/squirrelmail.conf

REQD_DIRS+=		${SMDIR} ${SMDIR}/config

OWN_DIRS=		${DATADIR}
OWN_DIRS_PERMS=		${ATTACHMENTS_DIR} ${ROOT_USER} ${APACHE_GROUP} 730
OWN_DIRS_PERMS+=	${USER_PREFS_DIR} ${APACHE_USER} ${APACHE_GROUP} 755

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/squirrelmail.conf.dist
SUBST_FILES.paths+=	config/config_default.php
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@ATTACHMENTS_DIR@,${ATTACHMENTS_DIR},g'
SUBST_SED.paths+=	-e 's,@USER_PREFS_DIR@,${USER_PREFS_DIR},g'
SUBST_SED.paths+=	-e 's,@SMDIR@,${SMDIR},g'
SUBST_STAGE.paths=	post-patch

INSTALLATION_DIRS=	${PKGMANDIR}/man8
INSTALLATION_DIRS+=	share/examples/squirrelmail
INSTALLATION_DIRS+=	share/squirrelmail

post-extract:
	cp ${FILESDIR}/squirrelmail.conf.dist \
		${WRKDIR}/squirrelmail.conf.dist

pre-configure:
	find ${WRKSRC} \( -name '*.orig*' -o -name '.cvsignore' \) \
		-exec rm -f {} \;
# currently, we use iso_2022_jp.php in squirrelmail-decode package.
#
	rm -f ${WRKSRC}/functions/decode/iso_2022_jp.php

do-install:
	${INSTALL_DATA} ${WRKDIR}/squirrelmail.conf.dist ${EGDIR}/squirrelmail.conf
	cp -R ${WRKSRC}/* ${SMDIR}
	chown -R ${SHAREOWN}:${SHAREGRP} ${SMDIR}
	find ${SMDIR} -type d -exec chmod ${PKGDIRMODE} {} \;
	find ${SMDIR} -type f -exec chmod ${SHAREMODE} {} \;
	chmod a+x ${SMDIR}/config/conf.pl
	${INSTALL_DATA} ${WRKSRC}/data/index.php ${USER_PREFS_DIR}/
	${INSTALL_DATA} ${WRKSRC}/data/.htaccess ${USER_PREFS_DIR}/
	mv ${PREFIX}/share/squirrelmail/contrib/conf.pl.8 \
	  ${PREFIX}/${PKGMANDIR}/man8/squirrelmail-conf.pl.8

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
