# $NetBSD: Makefile,v 1.38 2004/04/26 20:42:00 jlam Exp $

DISTNAME=	squirrelmail-1.4.2
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squirrelmail/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	PHP4 webmail package

CONFLICTS=	sq-attachment-handlers-[0-9]*
CONFLICTS+=	sq-squirrelspell-[0-9]*

DEPENDS+=	php-gettext>=4.3.3:../../devel/php4-gettext

USE_BUILDLINK3=	yes
USE_LANGUAGES=	# empty
USE_PKGINSTALL=	yes
NO_BUILD=	yes
REPLACE_PERL=	config/conf.pl config/ri_once.pl

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	httpd
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/squirrelmail
SMDIR=			${PREFIX}/share/squirrelmail
DATADIR=		/var/spool/squirrelmail
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
	for file in config/config_default.php; do			\
		${SED}	-e "s|@ATTACHMENTS_DIR@|${ATTACHMENTS_DIR}|g"	\
			-e "s|@USER_PREFS_DIR@|${USER_PREFS_DIR}|g"	\
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done;								\
	${FIND} . \( -name "*.orig" -o -name ".cvsignore" \) -print	\
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
	${CHMOD} -R a-w ${SMDIR}
	${CP} ${WRKSRC}/data/index.php ${USER_PREFS_DIR}/
	${CP} ${WRKSRC}/data/.htaccess ${USER_PREFS_DIR}/

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
