# $NetBSD: Makefile,v 1.2 2005/07/14 11:50:08 adam Exp $

DISTNAME=	optipng-0.4.8
CATEGORIES=	graphics
MASTER_SITES=	http://www.cs.toronto.edu/~cosmin/pngtech/optipng/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.cs.toronto.edu/~cosmin/pngtech/optipng/
COMMENT=	Advances PNG Optimizer

WRKSRC=		${WRKDIR}/${DISTNAME}/src
BUILDLINK_DEPENDS.zlib+=	zlib>=1.2.2

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
