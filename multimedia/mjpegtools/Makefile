# $NetBSD: Makefile,v 1.3 2004/01/26 15:16:53 jmmv Exp $

DISTNAME=	mjpegtools-1.6.1.93
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mjpeg/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mjpeg.sourceforge.net/
COMMENT=	Programs for compressing video streams

DEPENDS+=		toolame>=02l:../../audio/toolame
BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm

USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make

USE_LIBTOOL=		yes
SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	mjpegtools.pc.in

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-large-file
CONFIGURE_ARGS+=	--with-lame-includes=${BUILDLINK_PREFIX.lame}
# XXX fix me
CONFIGURE_ARGS+=	--without-avifile

.include "../../audio/lame/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/ImageMagick/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
#.include "../../multimedia/avifile/buildlink2.mk"
# GTK+ support is disabled to avoid a dependancy on GTK+ when building GNOME2.
# This only disables the "glav" program.  If you really need it, please add an
# external package for it.
#.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
