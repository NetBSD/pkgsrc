# $NetBSD: Makefile,v 1.16.2.3 2002/06/23 18:40:37 jlam Exp $
#

DISTNAME=	gaim-0.58
CATEGORIES=	chat x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gaim/} \
		ftp://ftp.marko.net/pub/gaim/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://gaim.sourceforge.net/
COMMENT=	GTK+-based client for AOL's Instant Messenger chat system

USE_BUILDLINK2=		YES
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
CONFIGURE_ARGS+=	--enable-perl
CONFIGURE_ARGS+=	--enable-pixbuf

.include "../../audio/esound/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
