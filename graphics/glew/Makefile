# $NetBSD: Makefile,v 1.3 2008/09/01 10:06:33 dholland Exp $
#

DISTNAME=	glew-1.3.4-src
PKGNAME=	glew-1.3.4
PKGREVISION=	1
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

PKG_DESTDIR_SUPPORT=	user-destdir

post-extract:
	${LN} -s Makefile.netbsdelf ${WRKSRC}/config/Makefile.dragonfly
	${LN} -s Makefile.netbsdelf ${WRKSRC}/config/Makefile.netbsd

.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
