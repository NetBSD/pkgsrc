# $NetBSD: Makefile,v 1.5 2005/04/11 21:45:14 tv Exp $

DISTNAME=	phpldapadmin-${VERSION}
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=phpldapadmin/}

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://phpldapadmin.sourceforge.net/
COMMENT=	Set of PHP-scripts to administer an LDAP directory over the WWW

DEPENDS+=	php-ldap>=4.1.2:../../databases/php-ldap

VERSION=	0.9.5
NO_BUILD=	YES

INSTALLATION_DIRS=	${PREFIX}/share/phpldapadmin

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpldapadmin
	cd ${WRKSRC} && ${PAX}		\
		-s /\.#//		\
		-s /\.cvsignore//	\
		-rwppm . ${PREFIX}/share/phpldapadmin

.include "../../mk/bsd.pkg.mk"
