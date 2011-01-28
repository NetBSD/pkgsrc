# $NetBSD: Makefile,v 1.23 2011/01/28 07:28:16 adam Exp $

DISTNAME=	optipng-0.6.5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=optipng/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://optipng.sourceforge.net/
COMMENT=	Advanced PNG Optimizer
LICENSE=	png-license

PKG_DESTDIR_SUPPORT=		user-destdir

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	-prefix=${PREFIX}
CONFIGURE_ARGS+=	-with-system-zlib
#CONFIGURE_ARGS+=	-with-system-libpng

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.2
BUILDLINK_API_DEPENDS.png+=	png>=1.2.9nb2

INSTALLATION_DIRS+=		bin ${PKGMANDIR}/man1

.include "../../devel/zlib/buildlink3.mk"
#.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
