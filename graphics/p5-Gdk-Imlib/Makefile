# $NetBSD: Makefile,v 1.2 2005/07/13 18:01:31 jlam Exp $
#

.include "../../x11/p5-gtk/Makefile.common"

PKGNAME=	p5-Gdk-Imlib-${GTKPERL_VERSION}

MAINTAINER=	adrianp@NetBSD.org
COMMENT=	Perl bindings for Imlib

MAKE_PARAMS=	INSTALLMAN3DIR=${PREFIX}/man/man3
PERL5_PACKLIST=	auto/Gtk/Gdk/ImlibImage/.packlist

SUBPACKAGE=	GdkImlib

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/p5-gtk/Makefile.subpackage"
