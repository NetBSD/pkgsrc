# $NetBSD: Makefile,v 1.34 2004/04/26 22:07:06 snj Exp $

DISTNAME=	gabber-0.8.8
PKGREVISION=	5
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gabber/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://gabber.sourceforge.net/
COMMENT=	Gnome Jabber Client

USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	YES
USE_GNU_TOOLS+=		make
USE_X11BASE=		YES
USE_LIBTOOL=		YES

GCC_REQD+=		2.95.3

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-xmms --disable-sigctest

.include "../../devel/gal/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libsigc++10/buildlink3.mk"
.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk--/buildlink3.mk"
.include "../../x11/gnome--/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
