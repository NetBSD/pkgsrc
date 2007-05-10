# $NetBSD: Makefile,v 1.82.2.1 2007/05/10 08:02:30 ghen Exp $

DISTNAME=	squirrelmail-1.4.10
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squirrelmail/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	PHP webmail package

CONFLICTS=	sq-attachment-handlers-[0-9]*
CONFLICTS+=	sq-squirrelspell-[0-9]*
CONFLICTS+=	ja-squirrelspell-[0-9]*
CONFLICTS+=	ja-squirrelmail-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-gettext>=4.3.3:../../devel/php-gettext

USE_LANGUAGES=	# empty
NO_BUILD=	yes
USE_TOOLS+=	perl:run
REPLACE_PERL+=	config/conf.pl
BUILD_DEFS+=	APACHE_GROUP APACHE_USER VARBASE

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	httpd
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

EGDIR=			${PREFIX}/share/examples/squirrelmail
SMDIR=			${PREFIX}/share/squirrelmail
DATADIR=		${VARBASE}/spool/squirrelmail
ATTACHMENTS_DIR=	${DATADIR}/attachments
USER_PREFS_DIR=		${DATADIR}/data

MESSAGE_SUBST+=		SMDIR=${SMDIR:Q}
FILES_SUBST+=		SMDIR=${SMDIR:Q}

CONF_FILES=		${SMDIR:Q}/config/config_default.php \
			${SMDIR:Q}/config/config.php
CONF_FILES+=		${SMDIR:Q}/data/default_pref \
			${DATADIR:Q}/data/default_pref
CONF_FILES+=		${EGDIR:Q}/squirrelmail.conf \
			${PKG_SYSCONFDIR:Q}/squirrelmail.conf

REQD_DIRS+=		${SMDIR:Q} ${SMDIR:Q}/config

OWN_DIRS=		${DATADIR}
OWN_DIRS_PERMS=		${ATTACHMENTS_DIR} ${ROOT_USER} ${APACHE_GROUP} 730
OWN_DIRS_PERMS+=	${USER_PREFS_DIR} ${APACHE_USER} ${APACHE_GROUP} 755

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR:Q}/squirrelmail.conf.dist
SUBST_FILES.paths+=	config/config_default.php
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@ATTACHMENTS_DIR@,${ATTACHMENTS_DIR},g'
SUBST_SED.paths+=	-e 's,@USER_PREFS_DIR@,${USER_PREFS_DIR},g'
SUBST_SED.paths+=	-e 's,@SMDIR@,${SMDIR},g'
SUBST_STAGE.paths=	post-patch

INSTALLATION_DIRS=	${PKGMANDIR}/man8 share/examples/squirrelmail share/squirrelmail

post-extract:
	${CP} ${FILESDIR:Q}/squirrelmail.conf.dist \
		${WRKDIR:Q}/squirrelmail.conf.dist

pre-configure:
	${FIND} ${WRKSRC:Q} \( -name "*.orig*" -o -name ".cvsignore" \) -print | ${XARGS} ${RM} -f

do-install:
	${INSTALL_DATA} ${WRKDIR:Q}/squirrelmail.conf.dist ${EGDIR:Q}/squirrelmail.conf
	${CP} -R ${WRKSRC:Q}/* ${SMDIR:Q}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${SMDIR}
	${FIND} ${SMDIR} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${SMDIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}
	${CHMOD} a+x ${SMDIR:Q}/config/conf.pl
	${INSTALL_DATA} ${WRKSRC:Q}/data/index.php ${USER_PREFS_DIR:Q}/
	${INSTALL_DATA} ${WRKSRC:Q}/data/.htaccess ${USER_PREFS_DIR:Q}/
	${MV} ${PREFIX}/share/squirrelmail/contrib/conf.pl.8 \
	  ${PREFIX}/${PKGMANDIR}/man8/squirrelmail-conf.pl.8

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
