# $NetBSD: Makefile,v 1.45 2019/07/21 22:25:05 wiz Exp $
#

DISTNAME=		gdk_pixbuf2-${VERSION}
PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gdkpixbuf-${VERSION}
PKGREVISION=		1
COMMENT=		Ruby binding of GdkPixbuf-2.x
CATEGORIES=		graphics devel

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		ruby-gnome2-gdkpixbuf-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gio>=${VERSION}:../../devel/ruby-gnome2-gio
DEPENDS+=		gdk-pixbuf2>=2.36.4:../../graphics/gdk-pixbuf2

.include "../../devel/ruby-gnome2-gio/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
