# $NetBSD: Makefile,v 1.11 2001/12/13 03:23:35 reinoud Exp $
#

DISTNAME=	gaim-0.49
CATEGORIES=	chat x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gaim/} \
		ftp://ftp.marko.net/pub/gaim/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://gaim.sourceforge.net/
COMMENT=	GTK+-based client for AOL's Instant Messenger chat system

USE_BUILDLINK_ONLY=	YES
USE_GMAKE=		YES
USE_X11BASE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-artsc
CONFIGURE_ARGS+=	--disable-gnome
CONFIGURE_ARGS+=	--disable-nas
CONFIGURE_ARGS+=	--disable-panel
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-screensaver

CONFIGURE_ARGS+=	--enable-esd
CONFIGURE_ARGS+=	--enable-pixbuf

CONFIGURE_ENV+=		pixbufcfg="${GDK_PIXBUF_CONFIG}"

.include "../../audio/esound/buildlink.mk"
.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
