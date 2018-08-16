# $NetBSD: Makefile,v 1.46 2018/08/16 18:54:49 adam Exp $
#

DISTNAME=		scummvm-tools-1.4.0
PKGREVISION=		32
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scummvm/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://scummvm.sourceforge.net/
COMMENT=		Conversion and compression tools for ScummVM
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}

INSTALLATION_DIRS=	bin

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
