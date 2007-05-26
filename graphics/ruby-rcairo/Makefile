# $NetBSD: Makefile,v 1.2 2007/05/26 14:13:42 obache Exp $
#

DISTNAME=		rcairo-1.4.1
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=		graphics
MASTER_SITES=		http://cairographics.org/releases/

MAINTAINER=		dieter.NetBSD@pandora.be
HOMEPAGE=		http://cairographics.org/
COMMENT=		Ruby bindings for cairo

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.2.0

USE_TOOLS+=		pkg-config

RUBY_HAS_ARCHLIB=	YES
USE_RUBY_EXTCONF=	YES

.include "../../lang/ruby/modules.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
