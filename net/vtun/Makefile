# $NetBSD: Makefile,v 1.2 2000/04/27 06:34:44 tron Exp $
#

DISTNAME=	vtun-2.0
CATEGORIES=	net
MASTER_SITES=	http://vtun.netpedia.net/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://vtun.netpedia.net/

DEPENDS+=	liblzo-1.*:../../archivers/liblzo

GNU_CONFIGURE=	YES
USE_SSL=	YES
CONFIGURE_ARGS+=--with-crypto-headers=${SSLBASE}/include/openssl \
		--with-crypto-lib=${SSLBASE}/lib \
		--with-lzo-headers=${LOCALBASE}/include \
		--with-lzo-lib=${LOCALBASE}/lib
PLIST_SUBST+=	PREFIX=${PREFIX}
ALL_TARGET=	vtund

.include "../../mk/bsd.pkg.mk"
