# $NetBSD: Makefile,v 1.53 2008/07/27 00:03:42 bjs Exp $

PKGNAME=	glu-${MESA_PKGVERSION}
COMMENT=	GLU polygon tessellation facility for Mesa

CONFLICTS+=	Mesa-glx-[0-9]*
CONFLICTS+=	Mesa<3.2.1

MESA_HEADERS=	glu.h glu_mangle.h

.include "../../graphics/Mesa/Makefile.lib"

BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=${MESA_VERSION}
.include "../../graphics/MesaLib/buildlink3.mk"

post-extract:
	${GREP} '^[[:cntrl:]][g][l][u]' ${WRKSRC}/src/glu/sgi/glu.def \
	| ${SED} -e 's,^[[:cntrl:]],,' > ${WRKSRC}/src/glu/sgi/glu.sym

pre-build:
	cd ${WRKSRC} && ${RM} -fr src/glx src/mesa src/glut src/glw progs

.include "../../mk/bsd.pkg.mk"
