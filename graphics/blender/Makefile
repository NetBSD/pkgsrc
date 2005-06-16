# $NetBSD: Makefile,v 1.45 2005/06/16 06:57:57 jlam Exp $
#

DISTNAME=		blender-2.36
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.cs.umn.edu/pub/blender.org/source/ \
			http://download.blender.org/source/

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		http://www.blender.org/
COMMENT=		Fully integrated 3D graphics creation suite

BUILD_DEPENDS+=		scons>=0.96:../../devel/scons

WRKSRC=			${WRKDIR}/blender

USE_TOOLS+=		gmake
USE_LIBTOOL=		YES

LDFLAGS+=		-lcrypto

.include "options.mk"

INSTALLATION_DIRS=	bin

post-patch:
	${MV} ${WRKSRC}/SConstruct ${WRKSRC}/SConstruct.orig
	${AWK} '{print} NR == 54 {print "env.Append(LINKFLAGS = \"-Wl,-R${X11BASE}/lib,-R${LOCALBASE}/lib\")"}' ${WRKSRC}/SConstruct.orig > ${WRKSRC}/SConstruct

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
	${INSTALL_DATA} ${WRKSRC}/release/scripts/* ${PREFIX}/share/blender/scripts
	${INSTALL} ${WRKDIR}/blender/bin/blender ${PREFIX}/bin

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../lang/python/pyversion.mk"

.include "../../mk/bsd.pkg.mk"
