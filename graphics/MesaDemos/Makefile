# $NetBSD: Makefile,v 1.38 2015/04/25 14:23:06 tnn Exp $

DISTNAME=	mesa-demos-8.2.0
PKGNAME=	${DISTNAME:S/mesa-demos/MesaDemos/}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/demos/8.2.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cgit.freedesktop.org/mesa/demos/
COMMENT=	OpenGL examples and Demos
#LICENSE=	# Similar to mit but with SGI advertising clause.

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
