# $NetBSD: Makefile,v 1.1.1.1 1999/10/24 10:51:27 dbj Exp $
#

DISTNAME=	curl-6.1
CATEGORIES=	net
MASTER_SITES=	http://curl.haxx.nu/stuff/

MAINTAINER=	dbj@netbsd.org
HOMEPAGE=	http://curl.haxx.nu/

DEPENDS+=	openssl-0.9.2b:../../security/openssl
# curl can use the opendlap shared library to resolv ldap:// urls
#RUN_DEPENDS+=   openldap:../../databases/openldap

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
