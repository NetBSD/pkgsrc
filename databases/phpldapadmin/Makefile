# $NetBSD: Makefile,v 1.1.1.1 2004/08/29 15:56:34 recht Exp $

DISTNAME=	phpldapadmin-${VERSION}
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=phpldapadmin/}

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://phpldapadmin.sourceforge.net/
COMMENT=	Set of PHP-scripts to administer an LDAP directory over the WWW

DEPENDS+=	php-ldap>=4.1.2:../../databases/php4-ldap

VERSION=	0.9.4b
NO_BUILD=	YES
NO_BUILDLINK=	YES

INSTALLATION_DIRS=	${PREFIX}/share/phpldapadmin

do-install:
	cd ${WRKSRC} && ${PAX} -s ',\.cvsignore,,' \
		-rwppm . ${PREFIX}/share/phpldapadmin

.include "../../mk/bsd.pkg.mk"
