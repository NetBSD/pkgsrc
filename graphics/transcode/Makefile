# $NetBSD: Makefile,v 1.1.1.1 2003/06/23 07:09:32 mrg Exp $

DISTNAME=	transcode-0.6.6
CATEGORIES=	graphics
MASTER_SITES=	http://freshmeat.net/redir/transcode/15968/url_tgz/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://freshmeat.net/projects/transcode/
COMMENT=	transcode is a text console video-stream processing tool

BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm

USE_BUILDLINK2=		yes
USE_GMAKE=		yes

USE_SHLIBTOOL=		yes
SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-qt
CONFIGURE_ARGS+=	--without-libmpeg3
CONFIGURE_ARGS+=	--with-lame-includes=${BUILDLINK_PREFIX.lame}
CONFIGURE_ARGS+=	--with-dvdread-includes=${BUILDLINK_PREFIX.libdvdread}

#post-patch:
#	cd ${WRKSRC} && \
#	sed "s|/usr/local|${PREFIX}|g; s|include/libmpeg3|include/mpeg3|g; s| -ldl||g" acinclude.m4 > acinclude.new && \
#	${MV} acinclude.new acinclude.m4 && \
#	${ACLOCAL} && \
#	${AUTOHEADER} && \
#	${AUTOCONF}
#	-cd ${WRKSRC} && ${AUTOMAKE}

post-install:
	${LN} -s ../libxvidcore.so ${PREFIX}/lib/transcode/libxvidcore.so

.include "../../archivers/liblzo/buildlink2.mk"
.include "../../audio/liba52/buildlink2.mk"
.include "../../audio/lame/buildlink2.mk"
.include "../../audio/libogg/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../devel/libmpeg3/buildlink2.mk"
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

#.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
