# $NetBSD: Makefile,v 1.54 2009/06/10 17:33:34 wiz Exp $

PKGNAME=	glu-${MESA_PKGVERSION}
PKGREVISION=	1
COMMENT=	GLU polygon tessellation facility for Mesa

CONFLICTS+=	Mesa-glx-[0-9]*
CONFLICTS+=	Mesa<3.2.1

MESA_HEADERS=	glu.h glu_mangle.h

PKGCONFIG_OVERRIDE+=    src/glu/glu.pc.in
# no configure stage
PKGCONFIG_OVERRIDE_STAGE=       pre-build

.include "../../graphics/Mesa/Makefile.lib"

BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=${MESA_VERSION}
.include "../../graphics/MesaLib/buildlink3.mk"

post-extract:
	${GREP} '^[[:cntrl:]][g][l][u]' ${WRKSRC}/src/glu/sgi/glu.def \
	| ${SED} -e 's,^[[:cntrl:]],,' > ${WRKSRC}/src/glu/sgi/glu.sym

pre-build:
	cd ${WRKSRC} && ${RM} -fr src/glx src/mesa src/glut src/glw progs

# no configure phase
.include "../../mk/configure/pkg-config-override.mk"
.include "../../mk/bsd.pkg.mk"
