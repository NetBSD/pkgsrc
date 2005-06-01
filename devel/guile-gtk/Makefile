# $NetBSD: Makefile,v 1.23 2005/06/01 18:02:44 jlam Exp $
#

DISTNAME=		guile-gtk-0.40.91
CATEGORIES=		devel x11
MASTER_SITES=		http://www.ir.bbn.com/~gdt/pkgsrc-wip/

MAINTAINER=		gdt@ir.bbn.com
HOMEPAGE=		http://www.gnu.org/software/guile-gtk/
COMMENT=		Library to make GTK 1.2 accessible from guile

USE_LIBTOOL=		# defined

GNU_CONFIGURE=		# defined
MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}

# Skip glade, because it pulls in gnome-libs.
# Later, make a new package for just the glade parts,
# or a BUILD_DEF.
# glade-config may be in ${LOCALBASE}/bin, so force not using it.
CONFIGURE_ARGS+=	--without-glade

# .include "../../devel/libglade/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
