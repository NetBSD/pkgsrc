# $NetBSD: Makefile,v 1.5 2005/05/09 16:15:06 minskim Exp $

DISTNAME=	imp-h3-${IMPVER}
PKGNAME=	imp-${IMPVER}
CATEGORIES=	mail www
MASTER_SITES=	ftp://ftp.horde.org/pub/imp/tarballs/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.horde.org/imp/
COMMENT=	Internet Messaging Program

CONFLICTS+=	imp-3.*

DEPENDS+=	horde>=3.0.2:../../www/horde3
DEPENDS+=	php-imap>4.3.3:../../mail/php-imap

.include "../../mk/bsd.prefs.mk"

DOCDIR=		${PREFIX}/share/doc/imp
EGDIR=		${PREFIX}/share/examples/imp
HORDEDIR=	${PREFIX}/share/horde
IMPDIR=		${HORDEDIR}/imp
IMPVER=		4.0.3
PAXDIRS=	lib locale po scripts templates themes

MESSAGE_SUBST+=	IMPDIR=${IMPDIR}
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

USE_PKGINSTALL=		YES
PKG_SYSCONFSUBDIR?=	httpd

CONF_FILES=		${EGDIR}/imp.conf ${PKG_SYSCONFDIR}/imp.conf
CONF_FILES+=		${IMPDIR}/config/servers.php.dist \
			${IMPDIR}/config/servers.php
SUPPORT_FILES_PERMS+=	${IMPDIR}/config/conf.xml.dist \
			${IMPDIR}/config/conf.xml \
			${APACHE_USER} ${ROOT_GROUP} 0440
SUPPORT_FILES_PERMS+=	${IMPDIR}/config/filter.txt.dist \
			${IMPDIR}/config/filter.txt \
			${APACHE_USER} ${ROOT_GROUP} 0440
SUPPORT_FILES_PERMS+=	${IMPDIR}/config/header.txt.dist \
			${IMPDIR}/config/header.txt \
			${APACHE_USER} ${ROOT_GROUP} 0440
SUPPORT_FILES_PERMS+=	${IMPDIR}/config/menu.php.dist \
			${IMPDIR}/config/menu.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
SUPPORT_FILES_PERMS+=	${IMPDIR}/config/mime_drivers.php.dist \
			${IMPDIR}/config/mime_drivers.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
SUPPORT_FILES_PERMS+=	${IMPDIR}/config/motd.php.dist \
			${IMPDIR}/config/motd.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
SUPPORT_FILES_PERMS+=	${IMPDIR}/config/prefs.php.dist \
			${IMPDIR}/config/prefs.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
SUPPORT_FILES_PERMS+=	${IMPDIR}/config/trailer.txt.dist \
			${IMPDIR}/config/trailer.txt \
			${APACHE_USER} ${ROOT_GROUP} 0440

SUBST_CLASSES=		files
SUBST_STAGE.files=	post-build
SUBST_FILES.files=	imp.conf.dist
SUBST_SED.files=	-e "s|@IMPDIR@|${IMPDIR}|g"
SUBST_MESSAGE.files=	"Fixing configuration files."

.include "options.mk"

do-build:
	@${CP} ${FILESDIR}/imp.conf.dist ${WRKSRC}/imp.conf.dist
	@${CP} ${WRKSRC}/config/conf.xml ${WRKSRC}/config/conf.xml.dist
	@${FIND} ${WRKSRC} -name .htaccess -print | ${XARGS} ${RM} -f

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${IMPDIR}
	${INSTALL_DATA_DIR} ${IMPDIR}/config
	${INSTALL_DATA} ${WRKSRC}/imp.conf.dist ${EGDIR}/imp.conf
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCDIR}

.	for d in ${PAXDIRS}
		${INSTALL_DATA_DIR} ${IMPDIR}/${d}
.	endfor
.	undef d 

.	for d in ${PAXDIRS}
		cd ${WRKSRC}/${d} && ${PAX} -rw . ${IMPDIR}/${d}
.	endfor
.	undef d

	${INSTALL_DATA} ${WRKSRC}/config/*.dist ${IMPDIR}/config
	${INSTALL_DATA} ${WRKSRC}/*.php ${IMPDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${IMPDIR}
	${FIND} ${IMPDIR} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${IMPDIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE} 
	${CHOWN} ${APACHE_USER}:${ROOT_GROUP} ${IMPDIR}/config
	${CHMOD} 0750 ${IMPDIR}/config

.include "../../mk/bsd.pkg.mk"
