# $NetBSD: Makefile,v 1.6 2023/11/12 13:21:57 wiz Exp $

DISTNAME=	ftgl-2.1.3-rc5
PKGNAME=	${DISTNAME:S/-r/r/1}
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ftgl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/frankheckenbach/ftgl
COMMENT=	C++ library of Freetype2 in OpenGL applications
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/ftgl-2.1.3~rc5
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake gsed pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

CONFIGURE_ENV+=	ac_cv_path_DOXYGEN=no

CONFIGURE_ARGS+=	--disable-freetypetest
CONFIGURE_ARGS+=	--without-glut-inc
CONFIGURE_ARGS+=	--without-x

PKGCONFIG_OVERRIDE+=	ftgl.pc.in

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
