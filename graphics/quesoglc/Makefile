# $NetBSD: Makefile,v 1.2 2011/11/01 06:01:45 sbd Exp $
#

DISTNAME=	quesoglc-0.7.1-free
PKGNAME=	${DISTNAME:S/-free$//}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=quesoglc/}
EXTRACT_SUFX=	.tar.bz2

PKG_DESTDIR_SUPPORT=	user-destdir

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://quesoglc.sourceforge.net/
COMMENT=	Free implementation of the OpenGL Character Renderer (GLC)

WRKSRC=		${WRKDIR}/quesoglc-0.7.1
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config gmake
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--disable-executables

.include "../../converters/fribidi/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
