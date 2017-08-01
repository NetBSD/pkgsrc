# $NetBSD: Makefile,v 1.59 2017/08/01 14:59:00 wiz Exp $

DISTNAME=	MesaGLUT-7.9.2
# we have the autoconf patches from git, so call it 8.0.1.
PKGNAME=	glut-8.0.1
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/glut/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cgit.freedesktop.org/mesa/glut/
COMMENT=	GLUT Graphics library similar to SGI's OpenGL
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/Mesa-7.9.2
USE_TOOLS+=	autoreconf automake autoconf gmake pkg-config makedepend
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES

PKGCONFIG_OVERRIDE+=	src/glut/glx/glut.pc.in

CONFIGURE_ENV+=	"EXTRA_LIB_PATH=${LDFLAGS} ${COMPILER_RPATH_FLAG}${X11BASE}/lib -L${X11BASE}/lib"

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
