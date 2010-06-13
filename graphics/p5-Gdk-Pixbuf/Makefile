# $NetBSD: Makefile,v 1.24 2010/06/13 22:44:39 wiz Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

.include "../../x11/p5-gtk/Makefile.common"

PKGNAME=	p5-Gdk-Pixbuf-${GTKPERL_VERSION}
PKGREVISION=	16

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 Gtk::Gdk::Pixbuf

PERL5_PACKLIST=	auto/Gtk/Gdk/Pixbuf/.packlist
SUBPACKAGE=	GdkPixbuf

.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../x11/p5-gtk/Makefile.subpackage"
