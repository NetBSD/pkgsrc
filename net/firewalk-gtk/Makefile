# $NetBSD: Makefile,v 1.1.1.1 2001/10/11 15:13:49 agc Exp $

DISTNAME=	firewalk-1.0
PKGNAME=	firewalk-gtk-1.0
CATEGORIES=	net security
MASTER_SITES=	http://www.packetfactory.net/Projects/firewalk/

MAINTAINER=	xs@nitric.net
HOMEPAGE=	http://www.packetfactory.net/Projects/firewalk/
COMMENT=	Firewalk determines the filter rules on a packet forwarding device

WRKSRC=         ${WRKDIR}/${DISTNAME:C/f/F/}

GNU_CONFIGURE=	#defined
CONFIGURE_ENV+=	CFLAGS="-I${LOCALBASE}/include `gtk-config --cflags`"
CONFIGURE_ENV+= GTK_CFLAGS="`gtk-config --cflags`"

MAKE_ENV+=	LIBS="-L${LOCALBASE}/lib" FIREWALK_LOC=${LOCALBASE}

pre-install:
	${MV} ${WRKSRC}/firewalk.1 ${WRKSRC}/firewalk-gtk.1

.include "../../x11/gtk/buildlink.mk"
.include "../../devel/libnet/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
