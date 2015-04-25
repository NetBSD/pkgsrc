# $NetBSD: Makefile,v 1.7 2015/04/25 14:23:11 tnn Exp $

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

post-install:
	${INSTALL_DATA} ${WRKSRC}/glpng.htm ${DESTDIR}${PREFIX}/share/doc/glpng

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
