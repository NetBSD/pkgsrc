# $NetBSD: Makefile,v 1.8 2025/09/14 17:22:41 jakllsch Exp $

DISTNAME=	Argyll_V3.4.1_src
PKGNAME=	${DISTNAME:S/_V/cms-/:S/_src$//:tl}
CATEGORIES=	graphics
MASTER_SITES=	http://www.argyllcms.com/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.argyllcms.com/
COMMENT=	ICC compatible color management system
LICENSE=	gnu-agpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME:S/_src$//}
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	png/libpng.pc.in
PKGCONFIG_OVERRIDE+=	tiff/libtiff-4.pc.in
PKGCONFIG_OVERRIDE+=	xml/mxml.pc.in
PKGCONFIG_OVERRIDE+=	zlib/zlib.pc.in

TOOL_DEPENDS+=	jam>=2.5.2:../../devel/jam

do-build:
	cd ${WRKSRC} && ${SETENV} DESTDIR=${DESTDIR} PREFIX=${PREFIX} \
		REFSUBDIR=share/argyll/ref \
		${MAKE_ENV} jam -q -fJambase ${_MAKE_JOBS}

do-install:
	cd ${WRKSRC} && ${SETENV} DESTDIR=${DESTDIR} PREFIX=${PREFIX} \
		REFSUBDIR=share/argyll/ref \
		${MAKE_ENV} jam -q -fJambase ${_MAKE_JOBS} install
	${MV} ${DESTDIR}${PREFIX}/bin/License.txt \
		${DESTDIR}${PREFIX}/share/argyll/
	${MKDIR} ${DESTDIR}${PREFIX}/share/metainfo
	${MV} ${DESTDIR}${PREFIX}/bin/com.argyllcms.metainfo.xml \
		${DESTDIR}${PREFIX}/share/metainfo/

.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
