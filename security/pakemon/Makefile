# $NetBSD: Makefile,v 1.6 2001/08/27 14:35:14 tron Exp $

DISTNAME=	pakemon-0.3.1
CATEGORIES=	security
MASTER_SITES=	http://www.inas.mag.keio.ac.jp/ids/pakemon/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.inas.mag.keio.ac.jp/ids/pakemon/
COMMENT=	packet monster, an Open Source Intrusion Detection System

DEPENDS+=	libnet-*:../../devel/libnet
# libnids provides static library only, thus it isn't necessary at run-time,
# only at compile-time.
#
BUILD_DEPENDS+=	libnids-1.14:../../net/libnids
BUILD_DEPENDS+=	autoconf>=2.13:../../devel/autoconf

GNU_CONFIGURE=	yes

post-extract:
	${CP} ${WRKSRC}/pakemon.h ${WRKSRC}/pakemon.h.in

post-patch:
	cd ${WRKSRC}; autoreconf

.include "../../mk/bsd.pkg.mk"
