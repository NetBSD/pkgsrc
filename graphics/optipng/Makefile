# $NetBSD: Makefile,v 1.36 2020/03/20 11:57:51 nia Exp $

DISTNAME=	optipng-0.7.7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=optipng/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://optipng.sourceforge.net/
COMMENT=	Advanced PNG Optimizer
LICENSE=	zlib

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	-mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	-prefix=${PREFIX}
CONFIGURE_ARGS+=	-with-system-libpng
CONFIGURE_ARGS+=	-with-system-zlib

BUILDLINK_API_DEPENDS.png+=	png>=1.6.34
BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.2

INSTALLATION_DIRS+=		bin ${PKGMANDIR}/man1

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
