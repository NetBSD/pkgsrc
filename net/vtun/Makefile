# $NetBSD: Makefile,v 1.4 2000/06/06 07:21:46 kleink Exp $
#

DISTNAME=	vtun-2.3
CATEGORIES=	net
MASTER_SITES=	http://vtun.sourceforge.net/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://vtun.sourceforge.net/

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
