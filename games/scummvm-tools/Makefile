# $NetBSD: Makefile,v 1.26 2013/12/15 19:37:41 joerg Exp $
#

DISTNAME=		scummvm-tools-1.4.0
PKGREVISION=		15
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scummvm/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://scummvm.sourceforge.net/
COMMENT=		Conversion and compression tools for ScummVM
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}

INSTALLATION_DIRS=	bin

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
MAKE_ENV+=	CLANG_NO_OPT=-O0
.endif

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
