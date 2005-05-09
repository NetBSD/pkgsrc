# $NetBSD: Makefile,v 1.2 2005/05/09 16:15:06 minskim Exp $

DISTNAME=	turba-h3-${TURBAVER}
PKGNAME=	turba-${TURBAVER}
CATEGORIES=	mail www
MASTER_SITES=	ftp://ftp.horde.org/pub/turba/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.horde.org/turba/
COMMENT=	Horde contact management application

DEPENDS+=	horde>=3.0.0:../../www/horde3

.include "../../mk/bsd.prefs.mk"

DOCDIR=		${PREFIX}/share/doc/turba
EGDIR=		${PREFIX}/share/examples/turba
HORDEDIR=	${PREFIX}/share/horde
TURBADIR=	${HORDEDIR}/turba
TURBAVER=	2.0.2
PAXDIRS=	lib locale po scripts templates themes
USE_PERL5=	YES

MESSAGE_SUBST+=	TURBADIR=${TURBADIR}
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
REPLACE_PERL=	${WRKSRC}/scripts/ldap/addou.pl

USE_PKGINSTALL=		YES
PKG_SYSCONFSUBDIR?=	httpd

SUBST_CLASSES=		files
SUBST_STAGE.files=	post-build
SUBST_FILES.files=	turba.conf.dist
SUBST_SED.files=	-e "s|@TURBADIR@|${TURBADIR}|g"
SUBST_MESSAGE.files=	"Fixing configuration files."

CONF_FILES=		${EGDIR}/turba.conf ${PKG_SYSCONFDIR}/turba.conf
CONF_FILES_PERMS+=	${TURBADIR}/config/sources.php.dist \
			${TURBADIR}/config/sources.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES+=		${TURBADIR}/config/attributes.php.dist \
			${TURBADIR}/config/attributes.php
SUPPORT_FILES_PERMS+=	${TURBADIR}/config/conf.xml.dist \
			${TURBADIR}/config/conf.xml \
			${APACHE_USER} ${ROOT_GROUP} 0440
SUPPORT_FILES_PERMS+=	${TURBADIR}/config/menu.php.dist \
			${TURBADIR}/config/menu.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
SUPPORT_FILES_PERMS+=	${TURBADIR}/config/prefs.php.dist \
			${TURBADIR}/config/prefs.php \
			${APACHE_USER} ${ROOT_GROUP} 0440

.include "options.mk"

do-build:
	@${CP} ${FILESDIR}/turba.conf.dist ${WRKSRC}/turba.conf.dist
	@${CP} ${WRKSRC}/config/conf.xml ${WRKSRC}/config/conf.xml.dist
	@${FIND} ${WRKSRC} -name .htaccess -print | ${XARGS} ${RM} -f
	@${CHMOD} 0750 ${WRKSRC}/scripts/ldap/addou.pl

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${TURBADIR}
	${INSTALL_DATA_DIR} ${TURBADIR}/config
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/INSTALL ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/LDAP ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/RELEASE_NOTES ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/UPGRADING ${DOCDIR}

.	for d in ${PAXDIRS}
		${INSTALL_DATA_DIR} ${TURBADIR}/${d}
.	endfor
.	undef d

.	for d in ${PAXDIRS}
		cd ${WRKSRC}/${d} && ${PAX} -rw . ${TURBADIR}/${d}
.	endfor
.	undef d

	${INSTALL_DATA} ${WRKSRC}/config/*.dist ${TURBADIR}/config
	${INSTALL_DATA} ${WRKSRC}/*.php ${TURBADIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${TURBADIR}
	${FIND} ${TURBADIR} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${TURBADIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE} 
	${CHOWN} ${APACHE_USER}:${SHAREGRP} ${TURBADIR}/config
	${CHMOD} 0750 ${TURBADIR}/config

.include "../../mk/bsd.pkg.mk"
