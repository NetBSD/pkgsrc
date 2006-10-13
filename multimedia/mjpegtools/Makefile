# $NetBSD: Makefile,v 1.36 2006/10/13 12:51:27 tron Exp $

DISTNAME=	mjpegtools-1.8.0
PKGREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mjpeg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mjpeg.sourceforge.net/
COMMENT=	Programs for compressing video streams

CONFLICTS+=		mplex-[0-9]*
DEPENDS+=		toolame>=02l:../../audio/toolame
BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm

USE_TOOLS+=		gmake
USE_TOOLS+=		bash:run pkg-config

USE_LANGUAGES=		c c++

USE_LIBTOOL=		yes
SHLIBTOOL_OVERRIDE=	# empty
PKGCONFIG_OVERRIDE=	mjpegtools.pc.in
INFO_FILES=		# PLIST

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-libquicktime
CONFIGURE_ARGS+=	--enable-large-file
CONFIGURE_ARGS+=	--with-lame-includes=${BUILDLINK_PREFIX.lame}

.include "options.mk"

.include "../../audio/lame/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
#
# GTK+ support is disabled to avoid a dependency on GTK+ when building GNOME2.
# This only disables the "glav" program.  If you really need it, please add an
# external package for it.
#
#.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
