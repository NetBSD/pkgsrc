# $NetBSD: Makefile,v 1.62 2018/11/12 03:51:53 ryoon Exp $

DISTNAME=	guile-gnome-platform-2.16.5
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://ftp.gnu.org/gnu/guile-gnome/guile-gnome-platform/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/guile-gnome/
COMMENT=	Library to access gobject/glib/gtk and gnome from guile
LICENSE=	gnu-gpl-v2

DEPENDS+=	guile-slib>=3.2.5:../../devel/guile-slib

MAKE_JOBS_SAFE=		NO

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake makeinfo pkg-config
USE_LIBTOOL=		YES
INFO_FILES=		YES

# warnings on alpha (perhaps other 64-bit too?)
BUILDLINK_TRANSFORM+=	rm:-Werror

TEST_TARGET=		check

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
BUILDLINK_API_DEPENDS.guile-cairo+=	guile-cairo>=1.4.1nb1
.include "../../graphics/guile-cairo/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../lang/guile20/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
