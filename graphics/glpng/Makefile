# $NetBSD: Makefile,v 1.8 2025/08/20 11:34:59 wiz Exp $

DISTNAME=	1079563a36edfe10a5f5d79ad38fe465425b989e
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://repo.or.cz/w/glpng.git/snapshot/
PKGNAME=	glpng-1.46

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Load PNG images directly as OpenGL textures

USE_CMAKE=		yes
INSTALLATION_DIRS+=	share/doc/glpng
WRKSRC=			${WRKDIR}/glpng

CMAKE_CONFIGURE_ARGS+=  -DCMAKE_POLICY_VERSION_MINIMUM=3.5

post-install:
	${INSTALL_DATA} ${WRKSRC}/glpng.htm ${DESTDIR}${PREFIX}/share/doc/glpng

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
