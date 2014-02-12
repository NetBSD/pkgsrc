# $NetBSD: Makefile,v 1.46 2014/02/12 23:17:46 tron Exp $

DISTNAME=	guile-gnome-platform-2.16.1
PKGREVISION=	32
CATEGORIES=	devel
MASTER_SITES=	http://ftp.gnu.org/gnu/guile-gnome/guile-gnome-platform/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/guile-gnome/
COMMENT=	Library to access gobject/glib/gtk and gnome from guile
LICENSE=	gnu-gpl-v2

DEPENDS+=	guile-slib>=2.4.2:../../devel/guile-slib

MAKE_JOBS_SAFE=		NO

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake makeinfo pkg-config
USE_LIBTOOL=		YES
INFO_FILES=		YES

# warnings on alpha (perhaps other 64-bit too?)
BUILDLINK_TRANSFORM+=	rm:-Werror

post-install:
	rm -f ${DESTDIR}${PREFIX}/share/guile-gnome-2/gnome/overrides/gtk.defs.orig

# XXX This should arguably be split into separate packages.

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/g-wrap/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/guile-cairo/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
