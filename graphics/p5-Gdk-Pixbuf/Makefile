# $NetBSD: Makefile,v 1.18 2006/11/08 13:40:33 obache Exp $
#

.include "../../x11/p5-gtk/Makefile.common"

PKGNAME=	p5-Gdk-Pixbuf-${GTKPERL_VERSION}
PKGREVISION=	12

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 Gtk::Gdk::Pixbuf

PERL5_PACKLIST=	auto/Gtk/Gdk/Pixbuf/.packlist
SUBPACKAGE=	GdkPixbuf

.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../x11/p5-gtk/Makefile.subpackage"
