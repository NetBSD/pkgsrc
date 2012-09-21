# $NetBSD: Makefile,v 1.27 2012/09/21 04:07:22 taca Exp $

DISTNAME=	optipng-0.7.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=optipng/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://optipng.sourceforge.net/
COMMENT=	Advanced PNG Optimizer
LICENSE=	zlib

PKG_DESTDIR_SUPPORT=		user-destdir

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	-prefix=${PREFIX}
CONFIGURE_ARGS+=	-with-system-zlib
CONFIGURE_ARGS+=	-with-system-libpng

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.2
BUILDLINK_API_DEPENDS.png+=	png>=1.2.9nb2

INSTALLATION_DIRS+=		bin ${PKGMANDIR}/man1

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
