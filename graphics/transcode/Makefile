# $NetBSD: Makefile,v 1.17 2003/09/22 10:45:20 seb Exp $

DISTNAME=	transcode-0.6.9
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.zebra.fh-weingarten.de/~transcode/pre/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.theorie.physik.uni-goettingen.de/~ostreich/transcode/
COMMENT=	Command line video-stream processing tool

BUILD_DEPENDS+=		nasm>=0.98.36:../../devel/nasm

USE_BUILDLINK2=		yes
USE_GMAKE=		yes

USE_LIBTOOL=		yes
SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-qt
# when libmpeg3 is a shlib.
CONFIGURE_ARGS+=	--without-libmpeg3

.if exists(${X11BASE}/lib/libXv.so)
PLIST_SUBST+=		FILTERPV=filter_pv.so
.else
PLIST_SUBST+=		FILTERPV=filter_pv.a
.endif

# this used to operate on acinclude.m4 and run aclocal, but running
# aclocal here breaks due to missing DLFCN checking
post-patch:
	cd ${WRKSRC} && \
	sed "s|/usr/local|${PREFIX}|g; s|include/libmpeg3|include/mpeg3|g; s|-ldl -lm|-lm|g" configure > configure.new && \
	${MV} configure.new configure && ${CHMOD} a+x configure
	-cd ${WRKSRC} && ${AUTOMAKE}

post-install:
	${LN} -s ../libxvidcore.so.2.1  ${PREFIX}/lib/transcode/libxvidcore.so.2

.include "../../archivers/liblzo/buildlink2.mk"
.include "../../audio/liba52/buildlink2.mk"
.include "../../audio/lame/buildlink2.mk"
.include "../../audio/libogg/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../devel/libmpeg3/buildlink2.mk"
# depends on a much later avifile than the one in pkgsrc
#.include "../../graphics/avifile/buildlink2.mk"
.include "../../graphics/ImageMagick/buildlink2.mk"
.include "../../graphics/mjpegtools/buildlink2.mk"
.include "../../graphics/xvidcore/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../misc/libdvdread/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
