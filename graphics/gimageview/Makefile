# $NetBSD: Makefile,v 1.35 2005/02/05 18:20:20 jklos Exp $

DISTNAME=	gimageview-0.2.27
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkmmviewer/}
PKGREVISION=	1

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gtkmmviewer.sourceforge.net/
COMMENT=	GTK+ based image viewer with tabbed browsing

USE_BUILDLINK3=		YES
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_X11=		YES

CONFIGURE_ARGS+=	--disable-xinetest
CONFIGURE_ARGS+=	--with-gtk2

# The 'gimv' binary is not linked against libpthread directly, but the
# librsvg library is.  So, when the program tries to dlopen(3) it, it
# causes a segfault due to NetBSD "limitations".
LDFLAGS.NetBSD+=	${PTHREAD_LDFLAGS}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../graphics/libwmf/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
