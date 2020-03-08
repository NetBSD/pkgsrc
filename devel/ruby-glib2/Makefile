# $NetBSD: Makefile,v 1.2 2020/03/08 16:47:41 wiz Exp $
#

DISTNAME=		glib2-${VERSION}
COMMENT=		Ruby binding of GLib-2.x
PKGREVISION=		1
CATEGORIES=		devel

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		ruby-gnome2-glib-[0-9]*
SUPERSEDES+=		ruby-gnome2-glib-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-native-package-installer>=1.0.3:../../devel/ruby-native-package-installer
DEPENDS+=		${RUBY_PKGPREFIX}-pkg-config>=1.3.5:../../devel/ruby-pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
