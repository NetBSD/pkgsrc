# $NetBSD: Makefile,v 1.21 2020/04/23 16:57:30 nia Exp $

DISTNAME=	ffmpeg2theora-0.30
PKGREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	http://v2v.cc/~j/ffmpeg2theora/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://v2v.cc/~j/ffmpeg2theora/
COMMENT=	Simple converter to create Ogg Theora files
LICENSE=	gnu-gpl-v3

USE_TOOLS+=		pkg-config

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

# for rintf(3)
LDFLAGS.Linux+=	-lm
LDFLAGS.SunOS+=	-lm

SCONS_ARGS=	-C ${WRKSRC} destdir=${DESTDIR:Q} prefix=${PREFIX:Q}
SCONS_ARGS+=	APPEND_CCFLAGS=${CFLAGS:Q}
SCONS_ARGS+=	APPEND_LINKFLAGS=${LDFLAGS:Q}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONSBIN} ${SCONS_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ffmpeg2theora ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ffmpeg2theora.1 \
	  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
PYTHON_FOR_BUILD_ONLY?=	yes
.include "../../devel/scons/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
