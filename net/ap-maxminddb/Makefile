# $NetBSD: Makefile,v 1.1 2025/03/06 01:17:36 manu Exp $

DISTNAME=	${GITHUB_PROJECT}-${GITHUB_RELEASE}
PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME:S/mod_//}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=maxmind/}
GITHUB_PROJECT=	mod_maxminddb
GITHUB_RELEASE=	1.2.0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/maxmind/mod_maxminddb/
COMMENT=	MaxMind DB geolocalisation Apache Module
LICENSE=	apache-2.0

APACHE_MODULE_NAME=	${DISTNAME:C/-.*//}.la

GNU_CONFIGURE=	yes
USE_LIBTOOL=	YES

INSTALLATION_DIRS+=	lib/httpd

do-install:
	cd ${WRKSRC}/src &&					\
	    libexecdir=`${APXS} -q LIBEXECDIR` &&		\
	    ${APXS} -i -S LIBEXECDIR=${DESTDIR}"$${libexecdir}"	\
	      -n maxminddb  mod_maxminddb.la


.include "../../mk/apache.mk"
.include "../../geography/libmaxminddb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
