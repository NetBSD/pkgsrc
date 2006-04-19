# $NetBSD: Makefile,v 1.8 2006/04/19 17:02:22 wiz Exp $

DISTNAME=	optipng-0.5
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.cs.toronto.edu/~cosmin/pngtech/optipng/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.cs.toronto.edu/~cosmin/pngtech/optipng/
COMMENT=	Advanced PNG Optimizer

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.2
BUILDLINK_API_DEPENDS.png+=	png>=1.2.9nb2

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
