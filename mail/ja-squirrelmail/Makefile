# $NetBSD: Makefile,v 1.15.2.2 2005/12/15 13:55:25 seb Exp $

DISTNAME=	squirrelmail-1.4.5
PKGNAME=	ja-${DISTNAME}
PKGREVISION=	3
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
USE_PKGINSTALL=	yes
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
FILES_SUBST+=		SMDIR=${SMDIR}

CONF_FILES=	${SMDIR}/config/config_default.php ${SMDIR}/config/config.php
CONF_FILES+=	${SMDIR}/data/default_pref ${DATADIR}/data/default_pref
CONF_FILES+=	${EGDIR}/squirrelmail.conf ${PKG_SYSCONFDIR}/squirrelmail.conf

REQD_DIRS=		${SMDIR} ${SMDIR}/config

OWN_DIRS=		${DATADIR}
OWN_DIRS_PERMS=		${ATTACHMENTS_DIR} ${ROOT_USER} ${APACHE_GROUP} 730
OWN_DIRS_PERMS+=	${USER_PREFS_DIR} ${APACHE_USER} ${APACHE_GROUP} 755

pre-configure:
	cd ${WRKSRC};							\
	for file in config/config_default.php; do			\
		${SED}	-e "s|@ATTACHMENTS_DIR@|${ATTACHMENTS_DIR}|g"	\
			-e "s|@USER_PREFS_DIR@|${USER_PREFS_DIR}|g"	\
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done;								\
	cd ${WRKSRC};							\
	${FIND} . \( -name "*.orig*" -o -name ".cvsignore" \) -print	\
		| ${XARGS} ${RM} -f

pre-install:
	@${SED}	${FILES_SUBST_SED} ${FILESDIR}/squirrelmail.conf.dist	\
		> ${WRKDIR}/squirrelmail.conf.dist

do-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${SMDIR}
	cd ${WRKDIR}; ${INSTALL_DATA} squirrelmail.conf.dist		\
		${EGDIR}/squirrelmail.conf
	${CP} -R ${WRKSRC}/* ${SMDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${SMDIR}
	${FIND} ${SMDIR} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${SMDIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}
	${CHMOD} a+x ${SMDIR}/config/conf.pl
	${INSTALL_DATA} ${WRKSRC}/data/index.php ${USER_PREFS_DIR}/
	${INSTALL_DATA} ${WRKSRC}/data/.htaccess ${USER_PREFS_DIR}/

.include "../../mk/bsd.pkg.mk"
