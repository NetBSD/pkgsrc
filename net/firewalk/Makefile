# $NetBSD: Makefile,v 1.6 2004/10/03 00:17:51 tv Exp $

DISTNAME=	firewalk-1.0
PKGREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	http://www.packetfactory.net/Projects/firewalk/

MAINTAINER=	xs@nitric.net
HOMEPAGE=	http://www.packetfactory.net/Projects/firewalk/
COMMENT=	Firewalk determines the filter rules on a packet forwarding device

WRKSRC=         ${WRKDIR}/${DISTNAME:C/f/F/}
USE_BUILDLINK3=	yes
GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	CFLAGS=-I${LOCALBASE}/include
CONFIGURE_ARGS+= --with-gtk=no

MAKE_ENV+=	FIREWALK_LOC=${LOCALBASE}

.include "../../devel/libnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
