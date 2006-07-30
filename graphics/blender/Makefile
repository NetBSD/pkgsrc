# $NetBSD: Makefile,v 1.57 2006/07/30 20:29:09 abs Exp $

DISTNAME=	blender-2.41
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.cs.umn.edu/pub/blender.org/source/ \
		http://download.blender.org/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.blender.org/
COMMENT=	Fully integrated 3D graphics creation suite

BUILD_DEPENDS+=		scons>=0.96:../../devel/scons

WRKSRC=			${WRKDIR}/blender
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++ 

LDFLAGS+=		-lcrypto

.include "options.mk"

INSTALLATION_DIRS=	bin

# remember to change the line number after an update
post-patch:
	${MV} ${WRKSRC}/SConstruct ${WRKSRC}/SConstruct.orig
	${AWK} '{print} NR == 62 {print "env.Append(LINKFLAGS = \"-Wl,-R${X11BASE}/lib,-R${LOCALBASE}/lib\")"}' ${WRKSRC}/SConstruct.orig > ${WRKSRC}/SConstruct

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		ADD_C_INCLUDE_DIRS=${WRKDIR}/.buildlink/include ADD_C_LIB_DIRS=${WRKDIR}/.buildlink/lib \
		${PREFIX}/bin/scons -C ${WRKSRC} prefix=${PREFIX}

do-install:
	${CP} -f ${WRKSRC}/blender ${WRKSRC}/blender-bin
	${SED} -e "s|__PREFIX__|${PREFIX}|g" files/blender > ${WRKDIR}/blender/bin/blender
	${CHMOD} +x ${WRKDIR}/blender/bin/blender
	${INSTALL_PROGRAM} ${WRKSRC}/blender-bin ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/blender/scripts
	${INSTALL_DATA} ${WRKSRC}/release/scripts/*.py \
		${PREFIX}/share/blender/scripts
	${INSTALL_DATA_DIR} ${PREFIX}/share/blender/scripts/bpymodules
	${INSTALL_DATA} ${WRKSRC}/release/scripts/bpymodules/*.py \
		${PREFIX}/share/blender/scripts/bpymodules
	${INSTALL} ${WRKDIR}/blender/bin/blender ${PREFIX}/bin

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../lang/python/pyversion.mk"

.include "../../mk/bsd.pkg.mk"
