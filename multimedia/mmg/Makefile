# $NetBSD: Makefile,v 1.14 2005/06/17 03:50:23 jlam Exp $
#

.include "../../multimedia/mkvtoolnix/Makefile.dist"
PKGNAME=        ${DISTNAME:S/mkvtoolnix/mmg/}

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.bunkus.org/videotools/mkvtoolnix/doc/mkvmerge-gui.html
COMMENT=        MKVtoolnix mkvmerge GUI

DEPENDS+=	${DISTNAME}:../../multimedia/mkvtoolnix

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c++

BUILD_TARGET=	src/mmg/mmg

SUBST_CLASSES=		man help

SUBST_STAGE.man=	pre-configure
SUBST_FILES.man=	doc/mmg.1
SUBST_SED.man=		's,(doc/,(${PREFIX}/share/doc/html/mmg/,g'
SUBST_MESSAGE.man=	"Fixing paths in manual page."

SUBST_STAGE.help=	pre-configure
SUBST_FILES.help=	src/mmg/mmg.cpp
SUBST_SED.help=		's,@HELPDIR@,${PREFIX}/share/doc/html/mmg,'
SUBST_MESSAGE.help=	"Fixing path to help data."

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mmg/mmg ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/mmg.1 ${PREFIX}/man/man1/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/mmg/images/
	${INSTALL_DATA} ${WRKSRC}/doc/images/*.gif \
		${PREFIX}/share/doc/html/mmg/images/
	${INSTALL_DATA} ${WRKSRC}/doc/mkvmerge-gui.* \
		${PREFIX}/share/doc/html/mmg/

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libebml/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../multimedia/libmatroska/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
