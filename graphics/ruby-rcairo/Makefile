# $NetBSD: Makefile,v 1.3 2007/05/26 16:52:24 obache Exp $
#

DISTNAME=		rcairo-1.4.1
PKGREVISION=		1
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=		graphics
MASTER_SITES=		http://cairographics.org/releases/

MAINTAINER=		dieter.NetBSD@pandora.be
HOMEPAGE=		http://cairographics.org/rcairo/
COMMENT=		Ruby bindings for cairo

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.2.0

USE_TOOLS+=		pkg-config

RUBY_HAS_ARCHLIB=	YES
USE_RUBY_EXTCONF=	YES
INSTALL_TARGET=		install

.include "../../lang/ruby/modules.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
