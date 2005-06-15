# $NetBSD: Makefile,v 1.17 2005/06/15 22:42:38 hubertf Exp $

DISTNAME=	mjpegtools-1.6.2
PKGREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mjpeg/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mjpeg.sourceforge.net/
COMMENT=	Programs for compressing video streams

DEPENDS+=		toolame>=02l:../../audio/toolame
BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm

USE_TOOLS+=		gmake

USE_LIBTOOL=		yes
SHLIBTOOL_OVERRIDE=	libtool
PKGCONFIG_OVERRIDE=	mjpegtools.pc.in

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-large-file
CONFIGURE_ARGS+=	--with-lame-includes=${BUILDLINK_PREFIX.lame}

.include "options.mk"

INFO_FILES=		mjpeg-howto.info

.include "../../audio/lame/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
# GTK+ support is disabled to avoid a dependency on GTK+ when building GNOME2.
# This only disables the "glav" program.  If you really need it, please add an
# external package for it.
#.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
