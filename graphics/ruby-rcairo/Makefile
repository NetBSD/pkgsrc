# $NetBSD: Makefile,v 1.1.1.1 2006/07/23 16:57:25 minskim Exp $
#

DISTNAME=		rcairo-1.2.0
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=		graphics
MASTER_SITES=		http://cairographics.org/releases/

MAINTAINER=		dieter.NetBSD@pandora.be
HOMEPAGE=		http://cairographics.org/
COMMENT=		Ruby bindings for cairo

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.2.0

USE_TOOLS+=		pkg-config

RUBY_HAS_ARCHLIB=	YES
USE_RUBY_SETUP=		YES

.include "../../lang/ruby/modules.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
