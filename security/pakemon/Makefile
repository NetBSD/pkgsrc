# $NetBSD: Makefile,v 1.16 2004/04/25 04:26:14 snj Exp $

DISTNAME=	pakemon-0.3.1
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.sfc.keio.ac.jp/~keiji/ids/pakemon/ \
		http://www.binarii.com/files/security/ \
		http://www.mirrors.wiretapped.net/security/network-intrusion-detection/pakemon/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://web.sfc.keio.ac.jp/~keiji/backup/ids/pakemon/index.html
COMMENT=	Packet monster, an Open Source Intrusion Detection System

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes

post-extract:
	${CP} ${WRKSRC}/pakemon.h ${WRKSRC}/pakemon.h.in

.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/libnet/buildlink3.mk"
.include "../../net/libnids/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
