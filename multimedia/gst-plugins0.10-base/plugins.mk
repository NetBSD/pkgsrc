# $NetBSD: plugins.mk,v 1.12 2016/02/25 15:49:43 jperkin Exp $
#
# This file is shared across the gst-plugins-{base,good} packages to
# simplify their code.  It provides a framework to write simple packages
# providing individual plugins; note that these packages must not include
# this file, but use the correct Makefile.common instead.
#

DISTNAME=	gst-plugins-${GST_PLUGINS0.10_TYPE}-${GST_PLUGINS0.10_VER}
PKGNAME=	${DISTNAME:S/plugins/plugins0.10/}
CATEGORIES=	multimedia gnome
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-plugins-${GST_PLUGINS0.10_TYPE}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gstreamer.net/
COMMENT=	Open source multimedia framework -

DISTINFO_FILE=	${.CURDIR}/../../multimedia/gst-plugins0.10-${GST_PLUGINS0.10_TYPE}/distinfo
FILESDIR=	${.CURDIR}/../../multimedia/gst-plugins0.10-${GST_PLUGINS0.10_TYPE}/files
PATCHDIR=	${.CURDIR}/../../multimedia/gst-plugins0.10-${GST_PLUGINS0.10_TYPE}/patches

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--disable-examples
CONFIGURE_ARGS+=	--disable-experimental
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--disable-valgrind
CONFIGURE_ARGS+=	--enable-external
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--enable-rpath
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/gst-plugins-0.10

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Msunpro)
# SunPro cc understands __func__ but CC does not, so disable explicitly.
CONFIGURE_ENV+=		have_func=no
.endif

# A package building a single plugin of gst-plugins0.10 has to include this
# file and define the following variables:
#    GST_PLUGINS0.10_NAME -  The name of the plugin, to be added to the package
#                            name and the comment.
#    GST_PLUGINS0.10_DIRS -  The directory where the plugin resides; a relative
#                            path from WRKSRC.
#    GST_PLUGINS0.10_FLAGS - The name of the flag used to enable the plugin.
#                            Defaults to GST_PLUGINS0.10_NAME.
.if defined(GST_PLUGINS0.10_NAME) && !empty(GST_PLUGINS0.10_NAME)
PKGNAME:=		${PKGNAME:S/${GST_PLUGINS0.10_TYPE}/${GST_PLUGINS0.10_NAME}/}
COMMENT+=		${GST_PLUGINS0.10_NAME} plugin

GST_PLUGINS0.10_FLAGS?=	${GST_PLUGINS0.10_NAME}
GST_PLUGINS0.10_DIRS?=	non-existent

.for _f_ in ${GST_PLUGINS0.10_FLAGS}
CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-${_f_}/--enable-${_f_}/}
.endfor

BUILD_DIRS=		${GST_PLUGINS0.10_DIRS}
INSTALL_DIRS=		${GST_PLUGINS0.10_DIRS}

# Fix paths to already installed libraries (by the gst-plugins package).
SUBST_CLASSES+=		libs
SUBST_MESSAGE.libs=	Fixing path to dependent libraries.
SUBST_STAGE.libs=	pre-configure
SUBST_FILES.libs=
.for _d_ in ${GST_PLUGINS0.10_DIRS}
SUBST_FILES.libs+=	${_d_}/Makefile.in
.endfor
SUBST_SED.libs=		-e 's|$$(top_builddir)/gst-libs/gst/.*/libgst|${BUILDLINK_PREFIX.gst-plugins0.10-${GST_PLUGINS0.10_TYPE}}/lib/libgst|g'

.include "../../multimedia/gst-plugins0.10-${GST_PLUGINS0.10_TYPE}/buildlink3.mk"
.endif

# libtool(1) of /usr/bin/libtool is required to build gstreamer 0.10.
# I have no idea how to fix the build with libtool-base from pkgsrc...
# https://bugzilla.gnome.org/show_bug.cgi?id=726518
SUBST_CLASSES.OpenBSD+=		fix-libtool
SUBST_STAGE.fix-libtool=	pre-configure
SUBST_MESSAGE.fix-libtool=	Fix libtool path
.for _d_ in pbutils audio app video fft cdda rtsp sdp riff tag interfaces rtp netbuffer
SUBST_FILES.fix-libtool+=	gst-libs/gst/${_d_}/Makefile.in
.endfor
#SUBST_SED.fix-libtool=		-e 's,--libtool=\"$$(top_builddir)/libtool\",--libtool=\"$${LIBTOOL}\",g'
SUBST_SED.fix-libtool=		-e 's,--libtool=\"$$(top_builddir)/libtool\",--libtool=\"/usr/bin/libtool\",g'

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
