# $NetBSD: Makefile,v 1.6 2006/04/10 05:34:46 jlam Exp $
#

.include "../../x11/p5-gtk/Makefile.common"

PKGNAME=	p5-Gdk-Imlib-${GTKPERL_VERSION}
PKGREVISION=	3

MAINTAINER=	adrianp@NetBSD.org
COMMENT=	Perl bindings for Imlib

PERL5_PACKLIST=	auto/Gtk/Gdk/ImlibImage/.packlist
SUBPACKAGE=	GdkImlib

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/p5-gtk/Makefile.subpackage"
