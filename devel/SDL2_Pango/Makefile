# $NetBSD: Makefile,v 1.4 2025/10/23 20:36:14 wiz Exp $

DISTNAME=	SDL2_Pango-2.1.5
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=markuskimius/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/markuskimius/SDL2_Pango/
COMMENT=	SDL2 frontend for pango
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	SDL2_Pango.pc.in

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
