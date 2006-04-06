# $NetBSD: Makefile,v 1.16 2006/04/06 06:22:32 reed Exp $

DISTNAME=	firewalk-5.0
PKGREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	http://www.packetfactory.net/firewalk/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.packetfactory.net/Projects/firewalk/
COMMENT=	Determines the filter rules on a packet forwarding device

WRKSRC=         ${WRKDIR}/Firewalk
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CFLAGS=-I${LOCALBASE}/include

BUILDLINK_API_DEPENDS.libnet+=	libnet-1.1.*

MAKE_ENV+=	FIREWALK_LOC=${PREFIX:Q}

.include "../../devel/libnet11/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/firewalk.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
