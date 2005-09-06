# $NetBSD: Makefile,v 1.14 2005/09/06 21:47:09 adrianp Exp $

DISTNAME=	phpldapadmin-${VERSION}
PKGREVISION=	5
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=phpldapadmin/}

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://phpldapadmin.sourceforge.net/
COMMENT=	Set of PHP-scripts to administer an LDAP directory over the WWW

DEPENDS+=	php-ldap>=4.1.2:../../databases/php-ldap

VERSION=	0.9.6c
NO_BUILD=	YES
USE_PKGINSTALL=	YES
BUILD_DEFS+=	WWW_USER

CONF_FILES=	${PREFIX}/share/examples/phpldapadmin/config.php.example \
		${PREFIX}/share/phpldapadmin/config.php
CONF_FILES+=	${PREFIX}/share/examples/phpldapadmin/phpldapadmin.conf \
		${PKG_SYSCONFDIR}/phpldapadmin.conf
SPECIAL_PERMS=	${PREFIX}/share/phpldapadmin/config.php \
		${WWW_USER} ${ROOT_GROUP} 0600

INSTALLATION_DIRS=	${PREFIX}/share/phpldapadmin

# NOTE: If you're running apache under an account other than www or
# are running a different web server under a specific user account
# you should set WWW_USER in your mk.conf.
#
.if !defined(WWW_USER)
WWW_USER=	${APACHE_USER}
.endif

do-configure:
	@${SED} -e "s|@LDAPADMINDIR@|${PREFIX}/share/phpldapadmin|g" \
		${FILESDIR}/phpldapadmin.conf > ${WRKDIR}/phpldapadmin.conf

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/phpldapadmin

	${INSTALL_DATA} ${WRKSRC}/config.php.example \
		${PREFIX}/share/examples/phpldapadmin
	${INSTALL_DATA} ${WRKDIR}/phpldapadmin.conf \
		${PREFIX}/share/examples/phpldapadmin

	${INSTALL_DATA_DIR} ${PREFIX}/share/phpldapadmin
	cd ${WRKSRC} && ${PAX}		\
		-s /\.#//		\
		-s /\.cvsignore//	\
		-s /\.\*.orig//		\
		-s /\.\*.example//	\
		-rwppm . ${PREFIX}/share/phpldapadmin

.include "../../mk/bsd.pkg.mk"
