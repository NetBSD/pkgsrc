# $NetBSD: Makefile,v 1.19 2007/02/22 19:26:52 wiz Exp $

DISTNAME=	firewalk-5.0
PKGREVISION=	2
CATEGORIES=	net security
MASTER_SITES=	http://www.packetfactory.net/firewalk/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.packetfactory.net/Projects/firewalk/
COMMENT=	Determines the filter rules on a packet forwarding device

WRKSRC=		${WRKDIR}/Firewalk
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CFLAGS=-I${LOCALBASE}/include

MAKE_ENV+=	FIREWALK_LOC=${PREFIX:Q}

.include "../../devel/libnet11/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/firewalk.8 ${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
