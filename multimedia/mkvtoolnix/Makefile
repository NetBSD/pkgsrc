# $NetBSD: Makefile,v 1.1.1.1 2004/04/10 12:44:31 salo Exp $
#

DISTNAME=	mkvtoolnix-0.8.6
CATEGORIES=	multimedia
MASTER_SITES=	http://www.bunkus.org/videotools/mkvtoolnix/sources/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.bunkus.org/videotools/mkvtoolnix/
COMMENT=	Set of tools to create, alter and inspect Matroska files

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-extra-libs=${PREFIX}
CONFIGURE_ARGS+=	--with-extra-includes=${PREFIX}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/liblzo/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libogg/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../multimedia/libmatroska/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
