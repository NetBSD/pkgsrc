# $NetBSD: Makefile,v 1.1.1.1 2010/02/15 16:38:15 wiz Exp $
#

DISTNAME=		libnjb-2.2.6
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libnjb/}

MAINTAINER=		ku3@sl.aanet.ru
HOMEPAGE=		http://libnjb.sourceforge.net/
COMMENT=		Communicating with some Creative and Dell audio players

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c c++

PKGCONFIG_OVERRIDE+=	libnjb.pc.in

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
