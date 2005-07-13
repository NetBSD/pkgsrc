# $NetBSD: Makefile,v 1.11 2005/07/13 18:01:31 jlam Exp $
#

.include "../../x11/p5-gtk/Makefile.common"

PKGNAME=	p5-Gdk-Pixbuf-${GTKPERL_VERSION}
PKGREVISION=	7

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 Gtk::Gdk::Pixbuf

MAKE_PARAMS=	INSTALLMAN3DIR=${PREFIX}/man/man3
PERL5_PACKLIST=	auto/Gtk/Gdk/Pixbuf/.packlist

SUBPACKAGE=	GdkPixbuf

.include "../../www/gtkhtml/buildlink3.mk"
.include "../../x11/p5-gtk/Makefile.subpackage"
