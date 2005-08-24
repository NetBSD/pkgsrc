# $NetBSD: Makefile,v 1.11.2.1 2005/08/24 13:06:03 salo Exp $

DISTNAME=	squirrelmail-1.4.5
PKGNAME=	ja-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squirrelmail/}
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_SUFX=	.tar.bz2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	http://www.yamaai-tech.com/~masato/Download/
PATCHFILES=	squirrelmail-1.4.5-ja-20050714-patch.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.squirrelmail.jp/
COMMENT=	PHP webmail package with Japanese localization

DEPENDS+=	php-gettext>=4.3.3:../../devel/php-gettext
DEPENDS+=	php-mbstring>=4.3.3:../../misc/php-mbstring
CONFLICTS=	sq-attachment-handlers-[0-9]*
CONFLICTS+=	sq-squirrelspell-[0-9]*
CONFLICTS+=	squirrelmail-[0-9]*

USE_LANGUAGES=	# empty
USE_PKGINSTALL=	yes
NO_BUILD=	yes
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

OWN_DIRS=		${DATADIR}
OWN_DIRS+=		${SMDIR} ${SMDIR}/config
OWN_DIRS_PERMS=		${ATTACHMENTS_DIR} ${ROOT_USER} ${APACHE_GROUP} 730
OWN_DIRS_PERMS+=	${USER_PREFS_DIR} ${APACHE_USER} ${APACHE_GROUP} 755

post-patch:
	cd ${WRKSRC};							\
	for f in config/config_default.php; do				\
		${SED}	-e "s|@ATTACHMENTS_DIR@|${ATTACHMENTS_DIR}|g"	\
			-e "s|@USER_PREFS_DIR@|${USER_PREFS_DIR}|g"	\
			$$f > $$f.fixed;				\
		${MV} -f $$f.fixed $$f;					\
	done;								\

pre-install:
	cd ${WRKSRC}; \
		${FIND} . \( -name "*.orig" -o -name '*.orig_dist' -o	\
				-name ".cvsignore" \) -print		\
		| ${XARGS} ${RM} -f
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
	${INSTALL_DATA} ${WRKSRC}/data/index.php ${USER_PREFS_DIR}/
	${INSTALL_DATA} ${WRKSRC}/data/.htaccess ${USER_PREFS_DIR}/

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
