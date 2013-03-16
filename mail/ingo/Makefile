# $NetBSD: Makefile,v 1.21 2013/03/16 07:21:21 obache Exp $

DISTNAME=	ingo-h3-${INGOVER}
PKGNAME=	ingo-${INGOVER}
PKGREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	http://ftp.horde.org/pub/ingo/ \
		ftp://ftp.horde.org/pub/ingo/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.horde.org/apps/ingo/
COMMENT=	Horde based generic and complete mail filter rule frontend
LICENSE=	apache-1.1

DEPENDS+=	horde>=3.2:../../www/horde

PKG_DESTDIR_SUPPORT=	destdir

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=	pax

DOCDIR=		${PREFIX}/share/doc/ingo
EGDIR=		${PREFIX}/share/examples/ingo
HORDEDIR=	${PREFIX}/share/horde
INGODIR=	${HORDEDIR}/ingo
INGOVER=	1.2.6
PAXDIRS=	lib locale po scripts templates themes

MESSAGE_SUBST+=	INGODIR=${INGODIR}
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

PKG_SYSCONFSUBDIR?=	httpd
USE_PKGINSTALL=		yes

SUBST_CLASSES+=		files
SUBST_STAGE.files=	post-build
SUBST_FILES.files=	ingo.conf.dist
SUBST_SED.files=	-e "s|@INGODIR@|${INGODIR}|g"
SUBST_MESSAGE.files=	Fixing configuration files.

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*/bin/php
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	scripts/upgrades/convert_prefs_to_sql.php

PKG_USERS_VARS+=	APACHE_USER
BUILD_DEFS=		APACHE_USER

CONF_FILES=		${EGDIR}/ingo.conf ${PKG_SYSCONFDIR}/ingo.conf
CONF_FILES_PERMS+=	${INGODIR}/config/conf.xml.dist \
			${INGODIR}/config/conf.xml \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${INGODIR}/config/backends.php.dist \
			${INGODIR}/config/backends.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${INGODIR}/config/fields.php.dist \
			${INGODIR}/config/fields.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${INGODIR}/config/prefs.php.dist \
			${INGODIR}/config/prefs.php \
			${APACHE_USER} ${ROOT_GROUP} 0440

.include "options.mk"

do-build:
	${CP} ${FILESDIR}/ingo.conf.dist ${WRKSRC}/ingo.conf.dist
	${CP} ${WRKSRC}/config/conf.xml ${WRKSRC}/config/conf.xml.dist
	${FIND} ${WRKSRC} -name .htaccess -print | ${XARGS} ${RM} -f

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${INGODIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${INGODIR}/config
	${INSTALL_DATA} ${WRKSRC}/ingo.conf.dist ${DESTDIR}${EGDIR}/ingo.conf
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/INSTALL ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/RELEASE_NOTES ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/UPGRADING ${DESTDIR}${DOCDIR}
.for d in ${PAXDIRS}
		${INSTALL_DATA_DIR} ${DESTDIR}${INGODIR}/${d:Q}
.endfor
.for d in ${PAXDIRS}
		cd ${WRKSRC}/${d:Q} && pax -rwpma . ${DESTDIR}${INGODIR}/${d:Q}
.endfor
	${INSTALL_DATA} ${WRKSRC}/config/*.dist ${DESTDIR}${INGODIR}/config
	${INSTALL_DATA} ${WRKSRC}/*.php ${DESTDIR}${INGODIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${INGODIR}
	${FIND} ${DESTDIR}${INGODIR} -type d -print | \
	${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${DESTDIR}${INGODIR} -type f -print | \
	${XARGS} ${CHMOD} ${SHAREMODE}
	${CHOWN} ${APACHE_USER}:${SHAREGRP} ${DESTDIR}${INGODIR}/config
	${CHMOD} 0750 ${DESTDIR}${INGODIR}/config

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
