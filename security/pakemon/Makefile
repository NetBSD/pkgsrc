# $NetBSD: Makefile,v 1.7 2001/09/27 23:18:39 jlam Exp $

DISTNAME=	pakemon-0.3.1
CATEGORIES=	security
MASTER_SITES=	http://www.inas.mag.keio.ac.jp/ids/pakemon/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.inas.mag.keio.ac.jp/ids/pakemon/
COMMENT=	packet monster, an Open Source Intrusion Detection System

DEPENDS+=	libnet-[0-9]*:../../devel/libnet
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
