# $NetBSD: Makefile,v 1.48 2024/05/08 21:32:18 khorben Exp $

DISTNAME=	phpldapadmin-${VERSION}
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_GITHUB:=leenooks/}
GITHUB_PROJECT=	phpLDAPadmin
GITHUB_TAG=	${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://phpldapadmin.sourceforge.net/
COMMENT=	Set of PHP-scripts to administer an LDAP directory over the WWW
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"
.include "../../lang/php/phpversion.mk"

DEPENDS+=	${PHP_PKG_PREFIX}-ldap>=4.1.2:../../databases/php-ldap
DEPENDS+=	${PHP_PKG_PREFIX}-gettext>=4.1.2:../../devel/php-gettext

USE_TOOLS+=	pax

VERSION=	1.2.6.7
NO_BUILD=	YES

CONF_FILES+=	${PREFIX}/share/examples/phpldapadmin/config.php.example \
		${PREFIX}/share/phpldapadmin/config/config.php
CONF_FILES+=	${PREFIX}/share/examples/phpldapadmin/phpldapadmin.conf \
		${PKG_SYSCONFDIR}/phpldapadmin.conf
PAX_DIRS=	config doc hooks htdocs lib locale queries templates tools

INSTALLATION_DIRS+= \
	share/doc/phpldapadmin share/examples/phpldapadmin \
	share/phpldapadmin/config

do-configure:
	${SED} -e "s|@LDAPADMINDIR@|${PREFIX}/share/phpldapadmin/htdocs|g" \
		${FILESDIR}/phpldapadmin.conf > ${WRKDIR}/phpldapadmin.conf
	${RM} -f ${WRKSRC}/.gitignore
	${FIND} ${WRKSRC} -type d | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${WRKSRC} -type f | ${XARGS} ${CHMOD} ${NONBINMODE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/config/config.php.example \
		${DESTDIR}${PREFIX}/share/examples/phpldapadmin/config.php.example
	${INSTALL_DATA} ${WRKDIR}/phpldapadmin.conf \
		${DESTDIR}${PREFIX}/share/examples/phpldapadmin/phpldapadmin.conf
	${INSTALL_DATA} ${WRKSRC}/index.php \
		${DESTDIR}${PREFIX}/share/phpldapadmin
.for i in ${PAX_DIRS}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/phpldapadmin/${i:Q}
	cd ${WRKSRC}/${i:Q} && ${FIND} . -type f \! -name '*.orig' -print | \
		 pax -rwppm  ${DESTDIR}${PREFIX}/share/phpldapadmin/${i:Q}
.endfor
	${INSTALL_DATA} ${WRKSRC}/INSTALL.md \
		${DESTDIR}${PREFIX}/share/doc/phpldapadmin
	${INSTALL_DATA} ${WRKSRC}/LICENSE \
		${DESTDIR}${PREFIX}/share/doc/phpldapadmin
	${INSTALL_DATA} ${WRKSRC}/VERSION \
		${DESTDIR}${PREFIX}/share/phpldapadmin

.include "../../mk/bsd.pkg.mk"
