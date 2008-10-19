# $NetBSD: Makefile,v 1.9 2008/10/19 19:18:10 he Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../x11/p5-gtk/Makefile.common"

PKGNAME=	p5-Gdk-Imlib-${GTKPERL_VERSION}
PKGREVISION=	5

MAINTAINER=	adrianp@NetBSD.org
COMMENT=	Perl bindings for Imlib

PERL5_PACKLIST=	auto/Gtk/Gdk/ImlibImage/.packlist
SUBPACKAGE=	GdkImlib

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/p5-gtk/Makefile.subpackage"
