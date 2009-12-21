# $NetBSD: Makefile,v 1.19 2009/12/21 07:22:14 adam Exp $

DISTNAME=	optipng-0.6.3
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=optipng/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://optipng.sourceforge.net/
COMMENT=	Advanced PNG Optimizer

PKG_DESTDIR_SUPPORT=		user-destdir

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.2
BUILDLINK_API_DEPENDS.png+=	png>=1.2.9nb2

INSTALLATION_DIRS+=		bin ${PKGMANDIR}/man1

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
