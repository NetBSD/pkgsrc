# $NetBSD: Makefile,v 1.1.1.1 2001/10/11 15:11:48 agc Exp $

DISTNAME=	firewalk-1.0
CATEGORIES=	net security
MASTER_SITES=	http://www.packetfactory.net/Projects/firewalk/

MAINTAINER=	xs@nitric.net
HOMEPAGE=	http://www.packetfactory.net/Projects/firewalk/
COMMENT=	Firewalk determines the filter rules on a packet forwarding device

WRKSRC=         ${WRKDIR}/${DISTNAME:C/f/F/}

GNU_CONFIGURE=	#defined
CONFIGURE_ENV+=	CFLAGS=-I${LOCALBASE}/include
CONFIGURE_ARGS+= --with-gtk=no

MAKE_ENV+=	LIBS="-L${LOCALBASE}/lib" FIREWALK_LOC=${LOCALBASE}

.include "../../devel/libnet/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
