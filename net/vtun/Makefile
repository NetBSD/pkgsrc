# $NetBSD: Makefile,v 1.6 2001/01/30 11:24:01 kleink Exp $
#

DISTNAME=	vtun-2.4
CATEGORIES=	net
MASTER_SITES=	http://vtun.sourceforge.net/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://vtun.sourceforge.net/

DEPENDS+=	liblzo-1.*:../../archivers/liblzo

GNU_CONFIGURE=	YES
USE_SSL=	YES
CONFIGURE_ARGS+=--with-ssl-headers=${SSLBASE}/include/openssl \
		--with-ssl-lib=${SSLBASE}/lib \
		--with-lzo-headers=${LOCALBASE}/include \
		--with-lzo-lib=${LOCALBASE}/lib
PLIST_SUBST+=	PREFIX=${PREFIX}
ALL_TARGET=	vtund

.include "../../mk/bsd.pkg.mk"
