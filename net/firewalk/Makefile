# $NetBSD: Makefile,v 1.3 2003/03/29 12:41:56 jmmv Exp $

DISTNAME=	firewalk-1.0
WRKSRC=         ${WRKDIR}/${DISTNAME:C/f/F/}
CATEGORIES=	net security
MASTER_SITES=	http://www.packetfactory.net/Projects/firewalk/

MAINTAINER=	xs@nitric.net
HOMEPAGE=	http://www.packetfactory.net/Projects/firewalk/
COMMENT=	Firewalk determines the filter rules on a packet forwarding device

USE_BUILDLINK2=	# defined
GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	CFLAGS=-I${LOCALBASE}/include
CONFIGURE_ARGS+= --with-gtk=no

MAKE_ENV+=	FIREWALK_LOC=${LOCALBASE}

.include "../../devel/libnet/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
