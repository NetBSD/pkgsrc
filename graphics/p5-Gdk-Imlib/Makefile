# $NetBSD: Makefile,v 1.20 2012/02/06 12:40:31 wiz Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

.include "../../x11/p5-gtk/Makefile.common"

PKGNAME=	p5-Gdk-Imlib-${GTKPERL_VERSION}
PKGREVISION=	14

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl bindings for Imlib

PERL5_PACKLIST=	auto/Gtk/Gdk/ImlibImage/.packlist
SUBPACKAGE=	GdkImlib

.include "../../graphics/imlib-gtk/buildlink3.mk"
.include "../../x11/p5-gtk/Makefile.subpackage"
