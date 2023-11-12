# $NetBSD: Makefile,v 1.30 2023/11/12 13:22:55 wiz Exp $

DISTNAME=	ffmpeg2theora-0.30
PKGREVISION=	14
CATEGORIES=	multimedia
MASTER_SITES=	http://v2v.cc/~j/ffmpeg2theora/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://v2v.cc/~j/ffmpeg2theora/
COMMENT=	Simple converter to create Ogg Theora files
LICENSE=	gnu-gpl-v3

USE_TOOLS+=		pkg-config

REPLACE_SH+=	version.sh

SCONS_BUILD_ARGS+=	APPEND_CCFLAGS=${CFLAGS:Q}
SCONS_BUILD_ARGS+=	APPEND_LINKFLAGS=${LDFLAGS:Q}
SCONS_INSTALL_ARGS+=	destdir=${DESTDIR:Q} prefix=${PREFIX:Q}

PYTHON_FOR_BUILD_ONLY=		yes

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/scons4/build.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
