# $NetBSD: Makefile,v 1.2 2004/09/24 20:47:09 kristerw Exp $

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
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpldapadmin
	cd ${WRKSRC} && ${PAX} \
		-rwppm . ${PREFIX}/share/phpldapadmin
	${RM} ${PREFIX}/share/phpldapadmin/.cvsignore

.include "../../mk/bsd.pkg.mk"
