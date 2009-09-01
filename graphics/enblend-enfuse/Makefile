# $NetBSD: Makefile,v 1.1.1.1 2009/09/01 14:39:28 adam Exp $

DISTNAME=	enblend-enfuse-3.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=enblend/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://enblend.sourceforge.net/
COMMENT=	Combines overlapping images without seams, with good exposure

LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--with-apple-opengl-framework
.else
CONFIGURE_ARGS+=	--with-x
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.endif

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/libxmi/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
