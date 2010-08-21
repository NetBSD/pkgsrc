# $NetBSD: Makefile,v 1.15 2010/08/21 16:34:56 seb Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

.include "../../x11/p5-gtk/Makefile.common"

PKGNAME=	p5-Gdk-Imlib-${GTKPERL_VERSION}
PKGREVISION=	9

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl bindings for Imlib

PERL5_PACKLIST=	auto/Gtk/Gdk/ImlibImage/.packlist
SUBPACKAGE=	GdkImlib

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/p5-gtk/Makefile.subpackage"
