# $NetBSD: Makefile,v 1.26 2011/01/13 13:38:13 wiz Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

.include "../../x11/p5-gtk/Makefile.common"

PKGNAME=	p5-Gdk-Pixbuf-${GTKPERL_VERSION}
PKGREVISION=	18

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 Gtk::Gdk::Pixbuf

PERL5_PACKLIST=	auto/Gtk/Gdk/Pixbuf/.packlist
SUBPACKAGE=	GdkPixbuf

.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../x11/p5-gtk/Makefile.subpackage"
