# $NetBSD: Makefile,v 1.8 2004/04/25 04:17:14 snj Exp $

DISTNAME=	firewalk-1.0
PKGNAME=	firewalk-gtk-1.0
PKGREVISION=	2
CATEGORIES=	net security
MASTER_SITES=	http://www.packetfactory.net/Projects/firewalk/

MAINTAINER=	xs@nitric.net
HOMEPAGE=	http://www.packetfactory.net/Projects/firewalk/
COMMENT=	Firewalk determines the filter rules on a packet forwarding device

WRKSRC=         ${WRKDIR}/${DISTNAME:C/f/F/}
USE_BUILDLINK3=	yes
GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	CFLAGS="-I${BUILDLINK_PREFIX.libnet}/include `gtk-config --cflags`"
CONFIGURE_ENV+= GTK_CFLAGS="`gtk-config --cflags`"

MAKE_ENV+=	FIREWALK_LOC=${LOCALBASE}

pre-install:
	${MV} ${WRKSRC}/firewalk.1 ${WRKSRC}/firewalk-gtk.1

.include "../../x11/gtk/buildlink3.mk"
.include "../../devel/libnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
