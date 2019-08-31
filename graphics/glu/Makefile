# $NetBSD: Makefile,v 1.68 2019/08/31 12:43:20 nia Exp $

DISTNAME=	glu-9.0.1
CATEGORIES=	graphics
MASTER_SITES=	https://mesa.freedesktop.org/archive/glu/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.freedesktop.org/mesa/glu
COMMENT=	OpenGL Utility Library
LICENSE=	sgi-free-software-b-v2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	glu.pc.in

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
