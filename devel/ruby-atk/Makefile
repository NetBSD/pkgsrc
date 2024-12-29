# $NetBSD: Makefile,v 1.9 2024/12/29 15:53:07 tsutsui Exp $

DISTNAME=		atk-${VERSION}
COMMENT=		Ruby binding of ATK-1.0.x or later
CATEGORIES=		devel

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		ruby-gnome2-atk-[0-9]*
SUPERSEDES+=		ruby-gnome2-atk-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-glib2>=${VERSION}:../../devel/ruby-glib2

BUILDLINK_API_DEPENDS.at-spi2-core+=	at-spi2-core>=2.54
.include "../../devel/at-spi2-core/buildlink3.mk"
.include "../../devel/ruby-glib2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
