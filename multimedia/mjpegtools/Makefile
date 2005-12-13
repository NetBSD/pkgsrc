# $NetBSD: Makefile,v 1.20 2005/12/13 15:53:53 ghen Exp $

DISTNAME=	mjpegtools-1.6.2
PKGREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mjpeg/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mjpeg.sourceforge.net/
COMMENT=	Programs for compressing video streams

DEPENDS+=		toolame>=02l:../../audio/toolame
BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm
DEPENDS+=		bash>=2:../../shells/bash

USE_TOOLS+=		gmake

USE_LIBTOOL=		yes
SHLIBTOOL_OVERRIDE=	libtool
PKGCONFIG_OVERRIDE=	mjpegtools.pc.in

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-large-file
CONFIGURE_ARGS+=	--with-lame-includes=${BUILDLINK_PREFIX.lame}

.include "options.mk"

EVAL_PREFIX+=		PREFIX.bash=bash
PREFIX.bash_DEFAULT=	${LOCALBASE}

SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	post-patch
SUBST_FILES.bash=	scripts/mpegtranscode
SUBST_FILES.bash+=	scripts/lav2avi.sh
SUBST_FILES.bash+=	scripts/lav2mpeg
SUBST_SED.bash=		-e 's,^\#!/bin/bash,\#!${PREFIX.bash}/bin/bash,'

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
