# $NetBSD: Makefile,v 1.5 2004/10/03 00:13:03 tv Exp $

DISTNAME=	transcode-0.6.12
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://www.zebra.fh-weingarten.de/~transcode/pre/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.zebra.fh-weingarten.de/~transcode/
COMMENT=	Command line video-stream processing tool

BUILD_DEPENDS+=		nasm>=0.98.36:../../devel/nasm

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make

USE_LIBTOOL=		yes
SHLIBTOOL_OVERRIDE=	libtool

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-qt
# when libmpeg3 is a shlib.
CONFIGURE_ARGS+=	--without-libmpeg3
CONFIGURE_ARGS+=	--with-default-xvid=xvid4
CONFIGURE_ARGS+=	--with-ft-prefix=${BUILDLINK_PREFIX.freetype2}

# this used to operate on acinclude.m4 and run aclocal, but running
# aclocal here breaks due to missing DLFCN checking
post-patch:
	-cd ${WRKSRC} && ${ACLOCAL} && ${AUTOCONF} && ${AUTOMAKE}
	cd ${WRKSRC} && \
	${SED} "s|/usr/local|${PREFIX}|g; s|include/libmpeg3|include/mpeg3|g; s|-ldl -lm|-lm|g" configure > configure.new && \
	${MV} configure.new configure && ${CHMOD} a+x configure
	${CP} ${FILESDIR}/strip_fPIC.sh ${WRKSRC}

post-install:
	${LN} -sf ../libxvidcore.so.4.0  ${PREFIX}/lib/transcode/libxvidcore.so.4

.include "../../archivers/liblzo/buildlink3.mk"
.include "../../audio/liba52/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../multimedia/libmpeg3/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
# depends on a much later avifile than the one in pkgsrc
#.include "../../multimedia/avifile/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/mjpegtools/buildlink3.mk"
.include "../../multimedia/xvidcore/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
