# $NetBSD: Makefile,v 1.2 2001/02/05 09:01:03 tron Exp $

DISTNAME=	pakemon-0.3.1
CATEGORIES=	security
MASTER_SITES=	http://www.inas.mag.keio.ac.jp/ids/pakemon/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.inas.mag.keio.ac.jp/ids/pakemon/

DEPENDS+=	libnet-*:../../devel/libnet
# libnids provides static library only, thus it isn't necessary at run-time,
# only at compile-time.
#
BUILD_DEPENDS+=	${LOCALBASE}/lib/libnids.a:../../net/libnids
BUILD_DEPENDS+=	${LOCALBASE}/bin/autoremake:../../devel/autoconf

GNU_CONFIGURE=	yes

post-extract:
	${CP} ${WRKSRC}/pakemon.h ${WRKSRC}/pakemon.h.in

post-patch:
	(cd ${WRKSRC}; autoreconf)

.include "../../mk/bsd.pkg.mk"
