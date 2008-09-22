# $NetBSD: Makefile,v 1.28 2008/09/22 20:21:03 joerg Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/mkvtoolnix/Makefile.dist"
PKGNAME=	${DISTNAME:S/mkvtoolnix/mmg/}

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.bunkus.org/videotools/mkvtoolnix/doc/mkvmerge-gui.html
COMMENT=	MKVtoolnix mkvmerge GUI

DEPENDS+=	${DISTNAME}{,nb[0-9]*}:../../multimedia/mkvtoolnix

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
	${INSTALL_PROGRAM} ${WRKSRC}/src/mmg/mmg ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/mmg.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/mmg/images/
	${INSTALL_DATA} ${WRKSRC}/doc/images/*.gif \
		${DESTDIR}${PREFIX}/share/doc/mmg/images/
	${INSTALL_DATA} ${WRKSRC}/doc/mkvmerge-gui.* \
		${DESTDIR}${PREFIX}/share/doc/mmg/

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libebml/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../multimedia/libmatroska/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/wxGTK26/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
