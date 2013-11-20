# $NetBSD: Makefile,v 1.44 2013/11/20 20:04:38 adam Exp $

DISTNAME=	hugin-2010.4.0
PKGREVISION=	27
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hugin/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hugin.sourceforge.net/
COMMENT=	Panorama photo stitcher

LICENSE=	gnu-gpl-v2

DEPENDS+=	autopano-sift-C>=2.5.1:../../graphics/autopano-sift-C
DEPENDS+=	enblend-enfuse>=4.0:../../graphics/enblend-enfuse
DEPENDS+=	p5-Image-ExifTool>=8.15:../../graphics/p5-Image-ExifTool

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		msgfmt pkg-config

# Workaround for a bug(?) in cmake. CXX_FLAGS will end containing
# '-pthread;-D_THREAD_SAFE' Happens at least on FreeBSD and DragonFly.
SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	post-configure
SUBST_FILES.pthread=	\
	${WRKSRC}/src/hugin1/hugin/CMakeFiles/hugin.dir/flags.make \
	${WRKSRC}/src/hugin1/hugin/CMakeFiles/hugin.dir/link.txt \
	${WRKSRC}/src/hugin1/base_wx/CMakeFiles/huginbasewx.dir/flags.make \
	${WRKSRC}/src/hugin1/stitch_project/CMakeFiles/hugin_stitch_project.dir/flags.make \
	${WRKSRC}/src/hugin1/stitch_project/CMakeFiles/hugin_stitch_project.dir/link.txt \
	${WRKSRC}/src/hugin1/nona_gui/CMakeFiles/nona_gui.dir/flags.make \
	${WRKSRC}/src/hugin1/nona_gui/CMakeFiles/nona_gui.dir/link.txt \
	${WRKSRC}/src/hugin1/ptbatcher/CMakeFiles/PTBatcher.dir/flags.make \
	${WRKSRC}/src/hugin1/ptbatcher/CMakeFiles/PTBatcher.dir/link.txt \
	${WRKSRC}/src/hugin1/ptbatcher/CMakeFiles/PTBatcherGUI.dir/flags.make \
	${WRKSRC}/src/hugin1/ptbatcher/CMakeFiles/PTBatcherGUI.dir/link.txt
SUBST_SED.pthread=	-e 's|-pthread;-D_THREAD_SAFE|-pthread -D_THREAD_SAFE|g'

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/libpano13/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.if ${OPSYS} != "Darwin"
.include "../../x11/wxGTK28/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
