# $NetBSD: Makefile,v 1.11 2008/01/09 21:48:51 adrianp Exp $

DISTNAME=	ingo-h3-${INGOVER}
PKGNAME=	ingo-${INGOVER}
CATEGORIES=	mail www
MASTER_SITES=	http://ftp.horde.org/pub/ingo/ \
		ftp://ftp.horde.org/pub/ingo/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.horde.org/ingo/
COMMENT=	Horde based generic and complete mail filter rule frontend

DEPENDS+=	horde>=3.0.0:../../www/horde

.include "../../mk/bsd.prefs.mk"

DOCDIR=		${PREFIX}/share/doc/ingo
EGDIR=		${PREFIX}/share/examples/ingo
HORDEDIR=	${PREFIX}/share/horde
INGODIR=	${HORDEDIR}/ingo
INGOVER=	1.1.5
PAXDIRS=	lib locale po scripts templates themes

MESSAGE_SUBST+=	INGODIR=${INGODIR:Q}
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

PKG_SYSCONFSUBDIR?=	httpd
USE_PKGINSTALL=		YES

SUBST_CLASSES+=		files
SUBST_STAGE.files=	post-build
SUBST_FILES.files=	ingo.conf.dist
SUBST_SED.files=	-e "s|@INGODIR@|${INGODIR}|g"
SUBST_MESSAGE.files=	Fixing configuration files.

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
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${INGODIR}
	${INSTALL_DATA_DIR} ${INGODIR}/config
	${INSTALL_DATA} ${WRKSRC}/ingo.conf.dist ${EGDIR}/ingo.conf
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/INSTALL ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/RELEASE_NOTES ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/UPGRADING ${DOCDIR}

.	for d in ${PAXDIRS}
		${INSTALL_DATA_DIR} ${INGODIR}/${d:Q}
.	endfor

.	for d in ${PAXDIRS}
		cd ${WRKSRC}/${d:Q} && ${PAX} -rwpma . ${INGODIR}/${d:Q}
.	endfor

	${INSTALL_DATA} ${WRKSRC}/config/*.dist ${INGODIR}/config
	${INSTALL_DATA} ${WRKSRC}/*.php ${INGODIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INGODIR}
	${FIND} ${INGODIR} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${INGODIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}
	${CHOWN} ${APACHE_USER}:${SHAREGRP} ${INGODIR}/config
	${CHMOD} 0750 ${INGODIR}/config

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
