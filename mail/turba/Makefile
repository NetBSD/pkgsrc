# $NetBSD: Makefile,v 1.38 2013/03/16 07:21:21 obache Exp $

DISTNAME=	turba-h3-${TURBAVER}
PKGNAME=	turba-${TURBAVER}
PKGREVISION=	2
CATEGORIES=	mail www
MASTER_SITES=	http://ftp.horde.org/pub/turba/ \
		ftp://ftp.horde.org/pub/turba/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.horde.org/turba/
COMMENT=	Horde contact management application
LICENSE=	apache-1.1

DEPENDS+=	horde>=3.3.7:../../www/horde

PKG_DESTDIR_SUPPORT=	destdir

.include "../../mk/bsd.prefs.mk"

DOCDIR=		${PREFIX}/share/doc/turba
EGDIR=		${PREFIX}/share/examples/turba
HORDEDIR=	${PREFIX}/share/horde
TURBADIR=	${HORDEDIR}/turba
TURBAVER=	2.3.6
PAXDIRS=	addressbooks lib locale po scripts templates themes js
USE_TOOLS+=	pax perl:run

MESSAGE_SUBST+=	TURBADIR=${TURBADIR:Q}
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}
REPLACE_PERL+=	${WRKSRC}/scripts/ldap/addou.pl

PKG_SYSCONFSUBDIR?=	httpd

PKG_USERS_VARS+=	APACHE_USER
BUILD_DEFS=		APACHE_USER

SUBST_CLASSES+=		files
SUBST_STAGE.files=	post-build
SUBST_FILES.files=	turba.conf.dist
SUBST_SED.files=	-e "s|@TURBADIR@|${TURBADIR}|g"
SUBST_MESSAGE.files=	Fixing configuration files.

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*/bin/php
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	scripts/import_vcards.php \
			scripts/upgrades/create_default_histories.php \
			scripts/upgrades/public_to_horde_share.php \
			scripts/import_squirrelmail_abook.php \
			scripts/upgrades/2.1_to_2.2_sql_schema.php \
			scripts/import_squirrelmail_file_abook.php \
			scripts/import_squirrelmail_sql_abook.php

CONF_FILES=		${EGDIR}/turba.conf ${PKG_SYSCONFDIR}/turba.conf
CONF_FILES_PERMS+=	${TURBADIR}/config/sources.php.dist \
			${TURBADIR}/config/sources.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES+=		${TURBADIR}/config/attributes.php.dist \
			${TURBADIR}/config/attributes.php
CONF_FILES_PERMS+=	${TURBADIR}/config/conf.xml.dist \
			${TURBADIR}/config/conf.xml \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${TURBADIR}/config/menu.php.dist \
			${TURBADIR}/config/menu.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${TURBADIR}/config/prefs.php.dist \
			${TURBADIR}/config/prefs.php \
			${APACHE_USER} ${ROOT_GROUP} 0440

.include "options.mk"

do-build:
	${CP} ${FILESDIR}/turba.conf.dist ${WRKSRC}/turba.conf.dist
	${CP} ${WRKSRC}/config/conf.xml ${WRKSRC}/config/conf.xml.dist
	${FIND} ${WRKSRC} -name .htaccess -print | ${XARGS} ${RM} -f
	${CHMOD} 0750 ${WRKSRC}/scripts/ldap/addou.pl

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${TURBADIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${TURBADIR}/config
	${INSTALL_DATA} ${WRKSRC}/turba.conf.dist ${DESTDIR}${EGDIR}/turba.conf
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/INSTALL ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/LDAP ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/RELEASE_NOTES ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/UPGRADING ${DESTDIR}${DOCDIR}

.	for d in ${PAXDIRS}
		${INSTALL_DATA_DIR} ${DESTDIR}${TURBADIR}/${d:Q}
.	endfor

.	for d in ${PAXDIRS}
		cd ${WRKSRC}/${d:Q} && pax -rwpma . \
			${DESTDIR}${TURBADIR}/${d:Q}
.	endfor

	${INSTALL_DATA} ${WRKSRC}/config/*.dist ${DESTDIR}${TURBADIR}/config
	${INSTALL_DATA} ${WRKSRC}/*.php ${DESTDIR}${TURBADIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${TURBADIR}
	${FIND} ${DESTDIR}${TURBADIR} -type d -print | \
	${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${DESTDIR}${TURBADIR} -type f -print | \
	${XARGS} ${CHMOD} ${SHAREMODE}
	${CHOWN} ${APACHE_USER}:${SHAREGRP} ${DESTDIR}${TURBADIR}/config
	${CHMOD} 0750 ${DESTDIR}${TURBADIR}/config

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
