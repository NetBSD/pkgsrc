# $NetBSD: Makefile,v 1.11 2006/02/05 23:10:17 joerg Exp $
#

.include "../../multimedia/mkvtoolnix/Makefile.dist"
PKGREVISION=	2

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.bunkus.org/videotools/mkvtoolnix/
COMMENT=	Set of tools to create, alter and inspect Matroska files

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--disable-gui

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/liblzo/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libebml/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../multimedia/libmatroska/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
