# $NetBSD: Makefile,v 1.1.1.1 2001/01/09 06:32:42 itojun Exp $

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
BUILD_DEPENDS+=	autoreconf:../../devel/autoconf

GNU_CONFIGURE=	yes

post-extract:
	${CP} ${WRKSRC}/pakemon.h ${WRKSRC}/pakemon.h.in

post-patch:
	(cd ${WRKSRC}; autoreconf)

.include "../../mk/bsd.pkg.mk"
