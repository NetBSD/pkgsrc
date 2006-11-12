# $NetBSD: Makefile,v 1.24 2006/11/12 02:27:57 rillig Exp $
#

.include "../../multimedia/mkvtoolnix/Makefile.dist"
PKGNAME=        ${DISTNAME:S/mkvtoolnix/mmg/}

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.bunkus.org/videotools/mkvtoolnix/doc/mkvmerge-gui.html
COMMENT=        MKVtoolnix mkvmerge GUI

DEPENDS+=	${DISTNAME}:../../multimedia/mkvtoolnix

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

BUILD_TARGET=	src/mmg/mmg

CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/doc

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_FILES.man=	doc/mmg.1
SUBST_SED.man=		-e 's,(doc/,(${PREFIX}/share/doc/mmg/,g'
SUBST_MESSAGE.man=	Fixing paths in manual page.

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mmg/mmg ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/mmg.1 ${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mmg/images/
	${INSTALL_DATA} ${WRKSRC}/doc/images/*.gif \
		${PREFIX}/share/doc/mmg/images/
	${INSTALL_DATA} ${WRKSRC}/doc/mkvmerge-gui.* \
		${PREFIX}/share/doc/mmg/

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libebml/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../multimedia/libmatroska/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
