# $NetBSD: Makefile,v 1.55 2008/01/18 05:06:39 tnn Exp $

DISTNAME=	gimageview-0.2.27
PKGREVISION=	14
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkmmviewer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtkmmviewer.sourceforge.net/
COMMENT=	GTK+ based image viewer with tabbed browsing

USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake intltool pkg-config

CONFIGURE_ARGS+=	--disable-xinetest
CONFIGURE_ARGS+=	--with-gtk2

# The 'gimv' binary is not linked against libpthread directly, but the
# librsvg library is.  So, when the program tries to dlopen(3) it, it
# causes a segfault due to NetBSD "limitations".
LDFLAGS.NetBSD+=	${PTHREAD_LDFLAGS}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/libwmf/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
