# $NetBSD: Makefile,v 1.5 2003/05/02 11:56:01 wiz Exp $

DISTNAME=	firewalk-1.0
PKGREVISION=	1
PKGNAME=	firewalk-gtk-1.0
WRKSRC=         ${WRKDIR}/${DISTNAME:C/f/F/}
CATEGORIES=	net security
MASTER_SITES=	http://www.packetfactory.net/Projects/firewalk/

MAINTAINER=	xs@nitric.net
HOMEPAGE=	http://www.packetfactory.net/Projects/firewalk/
COMMENT=	Firewalk determines the filter rules on a packet forwarding device

USE_BUILDLINK2=	# defined
GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	CFLAGS="-I${BUILDLINK_PREFIX.libnet}/include `gtk-config --cflags`"
CONFIGURE_ENV+= GTK_CFLAGS="`gtk-config --cflags`"

MAKE_ENV+=	FIREWALK_LOC=${LOCALBASE}

pre-install:
	${MV} ${WRKSRC}/firewalk.1 ${WRKSRC}/firewalk-gtk.1

.include "../../x11/gtk/buildlink2.mk"
.include "../../devel/libnet/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
