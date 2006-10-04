# $NetBSD: Makefile,v 1.23 2006/10/04 21:58:14 wiz Exp $

DISTNAME=	pakemon-0.3.1
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://www.binarii.com/files/security/ \
		http://www.mirrors.wiretapped.net/security/network-intrusion-detection/pakemon/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# removed in 2001
COMMENT=	Packet monster, an Open Source Intrusion Detection System

GNU_CONFIGURE=	yes

BUILDLINK_API_DEPENDS.libnet+=	libnet-1.0.*

post-extract:
	${CP} ${WRKSRC}/pakemon.h ${WRKSRC}/pakemon.h.in

.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/libnet/buildlink3.mk"
.include "../../net/libnids/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
