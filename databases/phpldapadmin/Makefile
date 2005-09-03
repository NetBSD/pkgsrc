# $NetBSD: Makefile,v 1.11 2005/09/03 16:14:18 adrianp Exp $

DISTNAME=	phpldapadmin-${VERSION}
PKGREVISION=	4
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=phpldapadmin/}

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://phpldapadmin.sourceforge.net/
COMMENT=	Set of PHP-scripts to administer an LDAP directory over the WWW

DEPENDS+=	php-ldap>=4.1.2:../../databases/php-ldap

VERSION=	0.9.6c
NO_BUILD=	YES
USE_PKGINSTALL=	YES
APACHE_USER?=	www

CONF_FILES=	${PREFIX}/share/examples/phpldapadmin/config.php.example \
		${PREFIX}/share/phpldapadmin/config.php
CONF_FILES+=	${PREFIX}/share/examples/phpldapadmin/phpldapadmin.conf \
		${PKG_SYSCONFDIR}/httpd/phpldapadmin.conf
SPECIAL_PERMS=	${PREFIX}/share/phpldapadmin/config.php \
		${APACHE_USER} wheel 0600

INSTALLATION_DIRS=	${PREFIX}/share/phpldapadmin

do-configure:
	@${SED} -e "s|@LDAPADMINDIR@|${PREFIX}/share/phpldapadmin|g" \
		${FILESDIR}/phpldapadmin.conf > ${WRKDIR}/phpldapadmin.conf

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/phpldapadmin

	${INSTALL_DATA} ${WRKSRC}/config.php.example \
		${PREFIX}/share/examples/phpldapadmin
	${INSTALL_DATA} ${WRKDIR}/phpldapadmin.conf \
		${PREFIX}/share/examples/phpldapadmin

	@${RM} ${WRKSRC}/config.php.example

	${INSTALL_DATA_DIR} ${PREFIX}/share/phpldapadmin
	cd ${WRKSRC} && ${PAX}		\
		-s /\.#//		\
		-s /\.cvsignore//	\
		-s /\.orig//		\
		-rwppm . ${PREFIX}/share/phpldapadmin

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
