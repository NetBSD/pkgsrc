# $NetBSD: Makefile,v 1.1.1.1 2003/06/23 07:16:21 mrg Exp $
#

.include "../../x11/p5-gtk/Makefile.common"

PKGNAME=	p5-Gdk-Pixbuf-${GTKPERL_VERSION}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Perl5 Gtk::Gdk::Pixbuf

MAKE_PARAMS=	INSTALLMAN3DIR=${PREFIX}/man/man3
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Gtk/Gdk/Pixbuf/.packlist

SUBPACKAGE=	GdkPixbuf

.include "../../www/gtkhtml/buildlink2.mk"
.include "../../x11/p5-gtk/Makefile.subpackage"
