# $NetBSD: Makefile,v 1.6 2005/05/19 23:12:17 seb Exp $

DISTNAME=	phpldapadmin-${VERSION}
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=phpldapadmin/}

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://phpldapadmin.sourceforge.net/
COMMENT=	Set of PHP-scripts to administer an LDAP directory over the WWW

DEPENDS+=	php-ldap>=4.1.2:../../databases/php-ldap

VERSION=	0.9.6c
NO_BUILD=	YES

INSTALLATION_DIRS=	${PREFIX}/share/phpldapadmin

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpldapadmin
	cd ${WRKSRC} && ${PAX}		\
		-s /\.#//		\
		-s /\.cvsignore//	\
		-rwppm . ${PREFIX}/share/phpldapadmin

.include "../../mk/bsd.pkg.mk"
