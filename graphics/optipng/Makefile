# $NetBSD: Makefile,v 1.5 2006/01/19 11:18:41 adam Exp $

DISTNAME=	optipng-0.5
CATEGORIES=	graphics
MASTER_SITES=	http://www.cs.toronto.edu/~cosmin/pngtech/optipng/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.cs.toronto.edu/~cosmin/pngtech/optipng/
COMMENT=	Advanced PNG Optimizer

BUILDLINK_DEPENDS.zlib+=	zlib>=1.2.2

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
