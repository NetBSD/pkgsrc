# $NetBSD: Makefile,v 1.11 2025/04/24 14:14:39 wiz Exp $
#

DISTNAME=		gdk_pixbuf2-${VERSION}
COMMENT=		Ruby binding of GdkPixbuf-2.x
PKGREVISION=		1
CATEGORIES=		graphics devel

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		ruby-gnome2-gdkpixbuf-[0-9]*
SUPERSEDES+=		ruby-gnome2-gdkpixbuf-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-gio2>=${VERSION}:../../devel/ruby-gio2

.include "../../devel/ruby-gio2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
