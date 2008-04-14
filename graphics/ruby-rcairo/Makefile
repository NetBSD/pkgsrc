# $NetBSD: Makefile,v 1.6 2008/04/14 20:09:32 jlam Exp $

DISTNAME=		cairo-1.6.0
PKGNAME=		${RUBY_PKGPREFIX}-r${DISTNAME}
CATEGORIES=		graphics

MAINTAINER=		dieter.NetBSD@pandora.be
HOMEPAGE=		http://cairographics.org/rcairo/
COMMENT=		Ruby bindings for cairo

USE_TOOLS+=		pkg-config
GEM_BUILD=		gemspec
GEM_CLEANBUILD=		Makefile *.o src/cairo.${RUBY_DLEXT} mkmf.log

# pkg-config.rb directly searches ${PKG_CONFIG_PATH} for the *.pc files
# to see if the dependency exists.  Point it to the pkgconfig directory
# under ${BUILDLINK_DIR} so it only finds what we want it to see.
#
MAKE_ENV+=		PKG_CONFIG_PATH=${BUILDLINK_DIR:Q}/lib/pkgconfig

.include "../../misc/rubygems/rubygem.mk"

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.2.0

.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
