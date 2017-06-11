# $NetBSD: Makefile,v 1.29 2017/06/11 05:51:40 tsutsui Exp $
#

DISTNAME=		glib2-${VERSION}
PKGNAME=		${RUBY_PKGPREFIX}-gnome2-glib-${VERSION}
COMMENT=		Ruby binding of GLib-2.x
CATEGORIES=		devel

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		ruby-gnome2-glib-[0-9]*
CONFLICTS+=		ruby[0-9][0-9]-gnome2-glib-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-native-package-installer>=1.0.3:../../devel/ruby-native-package-installer
DEPENDS+=		${RUBY_PKGPREFIX}-pkg-config>=1.2.2:../../devel/ruby-pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
