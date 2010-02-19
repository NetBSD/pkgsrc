# $NetBSD: Makefile,v 1.30 2010/02/19 20:38:40 joerg Exp $

DISTNAME=	phpldapadmin-${VERSION}
CATEGORIES=	databases www
PKGREVISION=	6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=phpldapadmin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://phpldapadmin.sourceforge.net/
COMMENT=	Set of PHP-scripts to administer an LDAP directory over the WWW

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"
.include "../../lang/php/phpversion.mk"

REPLACE_SH=	tools/po/make*

DEPENDS+=	${PHP_PKG_PREFIX}-ldap>=4.1.2:../../databases/php-ldap
DEPENDS+=	${PHP_PKG_PREFIX}-gettext>=4.1.2:../../devel/php-gettext

USE_TOOLS+=	pax

VERSION=	0.9.8.3
NO_BUILD=	YES

CONF_FILES+=  ${PREFIX}/share/examples/phpldapadmin/config.php.example \
		${PREFIX}/share/phpldapadmin/config/config.php
CONF_FILES+=	${PREFIX}/share/examples/phpldapadmin/phpldapadmin.conf \
		${PKG_SYSCONFDIR}/phpldapadmin.conf
PAX_DIRS=	config doc htdocs lib locale templates tools

do-configure:
	${SED} -e "s|@LDAPADMINDIR@|${PREFIX}/share/phpldapadmin/htdocs|g" \
		${FILESDIR}/phpldapadmin.conf > ${WRKDIR}/phpldapadmin.conf

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/phpldapadmin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/phpldapadmin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/phpldapadmin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/phpldapadmin/config

	${INSTALL_DATA} ${WRKSRC}/config/config.php.example \
		${DESTDIR}${PREFIX}/share/examples/phpldapadmin/config.php.example
	${INSTALL_DATA} ${WRKDIR}/phpldapadmin.conf \
		${DESTDIR}${PREFIX}/share/examples/phpldapadmin/phpldapadmin.conf

	${RM} ${WRKSRC}/.cvsignore
	${RM} ${WRKSRC}/config/.cvsignore

	${INSTALL_DATA} ${WRKSRC}/index.php \
		${DESTDIR}${PREFIX}/share/phpldapadmin

.for i in ${PAX_DIRS}
	cd ${WRKSRC}/${i:Q} && pax \
		-rwppm . ${DESTDIR}${PREFIX}/share/phpldapadmin/${i:Q}
.endfor

	${INSTALL_DATA} ${WRKSRC}/INSTALL \
		${DESTDIR}${PREFIX}/share/doc/phpldapadmin
	${INSTALL_DATA} ${WRKSRC}/LICENSE \
		${DESTDIR}${PREFIX}/share/doc/phpldapadmin
	${INSTALL_DATA} ${WRKSRC}/VERSION \
		${DESTDIR}${PREFIX}/share/phpldapadmin

	${FIND} ${DESTDIR}${PREFIX}/share/phpldapadmin -type d | \
		${XARGS} ${CHMOD} ${PKGDIRMODE}

.include "../../mk/bsd.pkg.mk"
