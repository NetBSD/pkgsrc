# $NetBSD: Makefile,v 1.14 2006/02/05 23:10:24 joerg Exp $

DISTNAME=	firewalk-5.0
PKGREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	http://www.packetfactory.net/firewalk/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.packetfactory.net/Projects/firewalk/
COMMENT=	Determines the filter rules on a packet forwarding device

WRKSRC=         ${WRKDIR}/Firewalk
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CFLAGS=-I${LOCALBASE}/include

BUILDLINK_DEPENDS.libnet+=	libnet-1.1.*

MAKE_ENV+=	FIREWALK_LOC=${PREFIX:Q}

.include "../../devel/libnet11/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/firewalk.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
