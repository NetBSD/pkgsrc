# $NetBSD: Makefile,v 1.32 2006/08/22 13:08:29 gdt Exp $
#

DISTNAME=		guile-gtk-0.5
CATEGORIES=		devel x11
MASTER_SITES=		${MASTER_SITE_GNU:=guile-gtk/}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/guile-gtk/
COMMENT=		Library to make GTK 1.2 accessible from guile

USE_LIBTOOL=		yes
USE_TOOLS+=		makeinfo

GNU_CONFIGURE=		yes
MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH:Q}
INFO_FILES=		yes

# Skip glade, because it pulls in gnome-libs.
# Later, make a new package for just the glade parts,
# or a PKG_OPTION.
CONFIGURE_ARGS+=	--without-glade
# .include "../../devel/libglade/buildlink3.mk"

.include "../../lang/guile/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
