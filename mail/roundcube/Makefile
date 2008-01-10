# $NetBSD: Makefile,v 1.7 2008/01/10 20:17:57 ghen Exp $
#

DISTNAME=	roundcubemail-0.1-rc2
PKGNAME=	roundcube-0.1rc2
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=roundcubemail/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://roundcube.net/
COMMENT=	Browser-based multilingual IMAP client

USE_LANGUAGES=	# none
NO_BUILD=	yes

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	httpd

PKG_GROUPS_VARS+=	APACHE_GROUP
PKG_USERS_VARS+=	APACHE_USER
BUILD_DEFS+=		VARBASE APACHE_USER APACHE_GROUP

RCDIR=		${PREFIX}/share/roundcube
EGDIR=		${PREFIX}/share/examples/roundcube
DOCDIR=		${PREFIX}/share/doc/roundcube
PAX_DIRS=	program skins

MESSAGE_SUBST+=	DOCDIR=${DOCDIR:Q} PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}
MESSAGE_SUBST+=	VARBASE=${VARBASE:Q}
FILES_SUBST+=	RCDIR=${RCDIR:Q}

OWN_DIRS+=	${PKG_SYSCONFDIR}/roundcube
OWN_DIRS_PERMS+=${VARBASE}/log/roundcube ${APACHE_USER} ${APACHE_GROUP} 0755
OWN_DIRS_PERMS+=${VARBASE}/tmp/roundcube ${APACHE_USER} ${APACHE_GROUP} 0755

CONF_FILES=	${EGDIR}/roundcube.conf ${PKG_SYSCONFDIR}/roundcube.conf
CONF_FILES_PERMS+=	\
	${EGDIR}/db.inc.php ${PKG_SYSCONFDIR}/roundcube/db.inc.php \
		${ROOT_USER} ${APACHE_GROUP} 0640 \
	${EGDIR}/main.inc.php ${PKG_SYSCONFDIR}/roundcube/main.inc.php \
		${ROOT_USER} ${APACHE_GROUP} 0640

SUBST_CLASSES+=		files
SUBST_STAGE.files=	do-configure
SUBST_FILES.files=	roundcube.conf
SUBST_FILES.files+=	config/main.inc.php.dist
SUBST_FILES.files+=	program/include/main.inc
SUBST_SED.files=	-e "s|@RCDIR@|${RCDIR}|g"
SUBST_SED.files+=	-e "s|@VARBASE@|${VARBASE}|g"
SUBST_SED.files+=	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"
SUBST_MESSAGE.files=	Fixing configuration files.

INSTALLATION_DIRS=	${RCDIR}/program ${RCDIR}/skins ${EGDIR}/SQL ${DOCDIR}

.include "options.mk"
.include "../../mk/apache.mk"

post-extract:
	${CP} ${FILESDIR}/roundcube.conf ${WRKSRC}/roundcube.conf

pre-install:
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM} -f

do-install:
	${INSTALL_DATA} ${WRKSRC}/roundcube.conf ${EGDIR}/roundcube.conf
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADING ${DOCDIR}

	${INSTALL_DATA} ${WRKSRC}/SQL/*.sql ${EGDIR}/SQL/

	${INSTALL_DATA} ${WRKSRC}/.htaccess ${RCDIR}/

	${INSTALL_DATA} ${WRKSRC}/index.php ${RCDIR}/

	${INSTALL_DATA} ${WRKSRC}/config/db.inc.php.dist ${EGDIR}/db.inc.php
	${INSTALL_DATA} ${WRKSRC}/config/main.inc.php.dist ${EGDIR}/main.inc.php

.for i in ${PAX_DIRS}
	cd ${WRKSRC}/${i} && ${PAX} -rw . ${RCDIR}/${i}
	${FIND} ${RCDIR}/${i} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	${FIND} ${RCDIR}/${i} -type d | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${RCDIR}/${i}
.endfor

.include "../../mk/bsd.pkg.mk"
