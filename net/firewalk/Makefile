# $NetBSD: Makefile,v 1.4 2004/01/20 12:22:19 agc Exp $

DISTNAME=	firewalk-1.0
CATEGORIES=	net security
MASTER_SITES=	http://www.packetfactory.net/Projects/firewalk/

MAINTAINER=	xs@nitric.net
HOMEPAGE=	http://www.packetfactory.net/Projects/firewalk/
COMMENT=	Firewalk determines the filter rules on a packet forwarding device

WRKSRC=         ${WRKDIR}/${DISTNAME:C/f/F/}
USE_BUILDLINK2=	# defined
GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	CFLAGS=-I${LOCALBASE}/include
CONFIGURE_ARGS+= --with-gtk=no

MAKE_ENV+=	FIREWALK_LOC=${LOCALBASE}

.include "../../devel/libnet/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
