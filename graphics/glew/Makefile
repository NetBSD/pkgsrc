# $NetBSD: Makefile,v 1.2 2007/02/15 14:58:20 joerg Exp $
#

PKGNAME=	glew-1.3.4
DISTNAME=	${PKGNAME}-src
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=glew/}
EXTRACT_SUFX=	.tgz
WRKSRC=		${WRKDIR}/glew

USE_LANGUAGES=	c c++

USE_TOOLS+=	gmake
MAKE_ENV+=	GLEW_DEST=${PREFIX:Q} X11=${PREFIX:Q} POPT=${CFLAGS:M*:Q}
MAKE_ENV+=	LDFLAGS.EXTRA=${X11_LDFLAGS:Q}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://glew.sourceforge.net/
COMMENT=	OpenGL Extension Wrangler Library

post-extract:
	${LN} -s Makefile.netbsdelf ${WRKSRC}/config/Makefile.dragonfly

.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
