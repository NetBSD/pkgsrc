# $NetBSD: Makefile,v 1.4 2021/12/08 16:05:05 adam Exp $
#

DISTNAME=		gdk_pixbuf2-${VERSION}
COMMENT=		Ruby binding of GdkPixbuf-2.x
PKGREVISION=		1
CATEGORIES=		graphics devel

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		ruby-gnome2-gdkpixbuf-[0-9]*
SUPERSEDES+=		ruby-gnome2-gdkpixbuf-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-gio2>=${VERSION}:../../devel/ruby-gio2
DEPENDS+=		gdk-pixbuf2>=2.36.4:../../graphics/gdk-pixbuf2

.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
