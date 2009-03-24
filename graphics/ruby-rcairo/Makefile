# $NetBSD: Makefile,v 1.10 2009/03/24 13:35:47 darcy Exp $

DISTNAME=		cairo-1.8.0
PKGNAME=		${RUBY_PKGPREFIX}-r${DISTNAME}
CATEGORIES=		graphics

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://cairographics.org/rcairo/
COMMENT=		Ruby bindings for cairo

USE_TOOLS+=		pkg-config
GEM_BUILD=		gemspec
GEM_CLEANBUILD=		Makefile *.o src/cairo.${RUBY_DLEXT} mkmf.log

.include "../../misc/rubygems/rubygem.mk"

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.2.0

.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
