# $NetBSD: Makefile,v 1.6 2006/04/06 06:22:05 reed Exp $

DISTNAME=	optipng-0.5
CATEGORIES=	graphics
MASTER_SITES=	http://www.cs.toronto.edu/~cosmin/pngtech/optipng/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.cs.toronto.edu/~cosmin/pngtech/optipng/
COMMENT=	Advanced PNG Optimizer

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.2

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
