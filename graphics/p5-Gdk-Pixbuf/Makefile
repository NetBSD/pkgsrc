# $NetBSD: Makefile,v 1.8 2004/10/03 00:14:56 tv Exp $
#

.include "../../x11/p5-gtk/Makefile.common"

PKGNAME=	p5-Gdk-Pixbuf-${GTKPERL_VERSION}
PKGREVISION=	5

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 Gtk::Gdk::Pixbuf

MAKE_PARAMS=	INSTALLMAN3DIR=${PREFIX}/man/man3
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Gtk/Gdk/Pixbuf/.packlist

SUBPACKAGE=	GdkPixbuf

.include "../../www/gtkhtml/buildlink3.mk"
.include "../../x11/p5-gtk/Makefile.subpackage"
