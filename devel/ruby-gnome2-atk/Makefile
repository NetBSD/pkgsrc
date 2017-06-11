# $NetBSD: Makefile,v 1.22 2017/06/11 05:51:40 tsutsui Exp $
#

DISTNAME=		atk-${VERSION}
PKGNAME=		${RUBY_PKGPREFIX}-gnome2-${DISTNAME}
COMMENT=		Ruby binding of ATK-1.0.x or later
CATEGORIES=		devel

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		ruby-gnome2-atk-[0-9]*
CONFLICTS+=		ruby[0-9][0-9]-gnome2-atk-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
