# $NetBSD: Makefile,v 1.5 2004/10/14 17:13:28 salo Exp $
#

.include "../../multimedia/mkvtoolnix/Makefile.dist"
PKGNAME=        ${DISTNAME:S/mkvtoolnix/mmg/}

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.bunkus.org/videotools/mkvtoolnix/doc/mkvmerge-gui.html
COMMENT=        MKVtoolnix mkvmerge GUI

DEPENDS+=	${DISTNAME}:../../multimedia/mkvtoolnix/

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_LANGUAGES=	c++
USE_X11=	yes

ALL_TARGET=	src/mmg/mmg

post-patch:
	@${SED} 's,@PREFIX@,${PREFIX},' ${WRKSRC}/doc/mmg.1 > \
		${WRKDIR}/mmg.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mmg/mmg ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKDIR}/mmg.1 ${PREFIX}/man/man1/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/mmg/images/
	${INSTALL_DATA} ${WRKSRC}/doc/images/*.png \
		${PREFIX}/share/doc/html/mmg/images/
	${INSTALL_DATA} ${WRKSRC}/doc/mkvmerge-gui.html \
		${PREFIX}/share/doc/html/mmg/guide.html

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libebml/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../multimedia/libmatroska/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
