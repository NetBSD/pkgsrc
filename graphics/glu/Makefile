# $NetBSD: Makefile,v 1.52 2008/06/27 13:24:39 tnn Exp $

PKGNAME=	glu-${MESA_PKGVERSION}
PKGREVISION=	1
COMMENT=	GLU polygon tessellation facility for Mesa

CONFLICTS+=	Mesa-glx-[0-9]*
CONFLICTS+=	Mesa<3.2.1

MESA_HEADERS=	glu.h glu_mangle.h

.include "../../graphics/Mesa/Makefile.lib"

BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=${MESA_VERSION}
.include "../../graphics/MesaLib/buildlink3.mk"

pre-build:
	cd ${WRKSRC} && ${RM} -fr src/glx src/mesa src/glut src/glw progs

.include "../../mk/bsd.pkg.mk"
