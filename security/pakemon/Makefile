# $NetBSD: Makefile,v 1.11 2003/07/17 22:53:09 grant Exp $

DISTNAME=	pakemon-0.3.1
CATEGORIES=	security
MASTER_SITES=	http://www.sfc.keio.ac.jp/~keiji/ids/pakemon/ \
		http://www.binarii.com/files/security/ \
		http://www.mirrors.wiretapped.net/security/network-intrusion-detection/pakemon/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://web.sfc.keio.ac.jp/~keiji/backup/ids/pakemon/index.html
COMMENT=	packet monster, an Open Source Intrusion Detection System

DEPENDS+=	libnet-[0-9]*:../../devel/libnet
# libnids provides static library only, thus it isn't necessary at run-time,
# only at compile-time.
#
BUILD_DEPENDS+=	libnids-1.14:../../net/libnids

GNU_CONFIGURE=	yes

post-extract:
	${CP} ${WRKSRC}/pakemon.h ${WRKSRC}/pakemon.h.in

.include "../../mk/bsd.pkg.mk"
