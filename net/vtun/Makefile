# $NetBSD: Makefile,v 1.1.1.1 2000/02/07 01:37:34 hubertf Exp $
#

DISTNAME=	vtun-2.0
CATEGORIES=	net
MASTER_SITES=	http://vtun.netpedia.net/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://vtun.netpedia.net/

DEPENDS+=	openssl-0.9.*:../../security/openssl
DEPENDS+=	liblzo-1.*:../../archivers/liblzo

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-crypto-headers=${LOCALBASE}/include/openssl \
		--with-crypto-lib=${LOCALBASE}/lib \
		--with-lzo-headers=${LOCALBASE}/include \
		--with-lzo-lib=${LOCALBASE}/lib
PLIST_SUBST+=	PREFIX=${PREFIX}
ALL_TARGET=	vtund

.include "../../mk/bsd.pkg.mk"
