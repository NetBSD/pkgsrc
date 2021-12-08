# $NetBSD: Makefile,v 1.4 2021/12/08 16:04:06 adam Exp $
#

DISTNAME=		atk-${VERSION}
COMMENT=		Ruby binding of ATK-1.0.x or later
PKGREVISION=		1
CATEGORIES=		devel

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		ruby-gnome2-atk-[0-9]*
SUPERSEDES+=		ruby-gnome2-atk-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-glib2>=${VERSION}:../../devel/ruby-glib2

.include "../../devel/atk/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
