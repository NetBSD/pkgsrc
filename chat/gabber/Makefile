# $NetBSD: Makefile,v 1.31 2004/03/08 19:40:36 jmmv Exp $

DISTNAME=	gabber-0.8.8
PKGREVISION=	5
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gabber/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://gabber.sourceforge.net/
COMMENT=	Gnome Jabber Client

DEPENDS+=	xdg-x11-dirs>=1.1:../../misc/xdg-x11-dirs

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_GNU_TOOLS+=		make
USE_X11BASE=		YES
USE_LIBTOOL=		YES

GCC_REQD+=		2.95.3

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-xmms --disable-sigctest

.include "../../devel/gal/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../devel/libsigc++10/buildlink2.mk"
.include "../../graphics/freetype-lib/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk--/buildlink2.mk"
.include "../../x11/gnome--/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
