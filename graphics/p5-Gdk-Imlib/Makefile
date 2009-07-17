# $NetBSD: Makefile,v 1.10 2009/07/17 18:00:16 adrianp Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../x11/p5-gtk/Makefile.common"

PKGNAME=	p5-Gdk-Imlib-${GTKPERL_VERSION}
PKGREVISION=	5

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl bindings for Imlib

PERL5_PACKLIST=	auto/Gtk/Gdk/ImlibImage/.packlist
SUBPACKAGE=	GdkImlib

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/p5-gtk/Makefile.subpackage"
