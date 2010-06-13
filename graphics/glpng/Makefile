# $NetBSD: Makefile,v 1.2 2010/06/13 22:44:33 wiz Exp $
#

DISTNAME=	glpng-1.45.20081203
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Load PNG images directly as OpenGL textures

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=		yes
INSTALLATION_DIRS+=	share/doc/glpng
WRKSRC=			${WRKDIR}/glpng

post-install:
	${INSTALL_DATA} ${WRKSRC}/glpng.htm ${DESTDIR}${PREFIX}/share/doc/glpng

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
