# $NetBSD: Makefile,v 1.32 2022/07/18 15:40:56 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/}
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - base plugins

USE_TOOLS+=	xgettext

GST_PLUGINS+=	adder
GST_PLUGINS+=	app
GST_PLUGINS+=	audioconvert
GST_PLUGINS+=	audiomixer
GST_PLUGINS+=	audiorate
GST_PLUGINS+=	audioresample
GST_PLUGINS+=	audiotestsrc
GST_PLUGINS+=	compositor
GST_PLUGINS+=	encoding
GST_PLUGINS+=	gio
GST_PLUGINS+=	gio-typefinder
GST_PLUGINS+=	overlaycomposition
GST_PLUGINS+=	pbtypes
GST_PLUGINS+=	playback
GST_PLUGINS+=	rawparse
GST_PLUGINS+=	subparse
GST_PLUGINS+=	tcp
GST_PLUGINS+=	typefind
GST_PLUGINS+=	videoconvert
GST_PLUGINS+=	videorate
GST_PLUGINS+=	videoscale
GST_PLUGINS+=	videotestsrc
GST_PLUGINS+=	volume

GST_PLUGINS+=	introspection
GST_PLUGINS+=	tools
GST_PLUGINS+=	nls

LDFLAGS.SunOS+=	-lsocket -lnsl

# for tests
# generate with:
# find work/gst-*/ -name *.so | sed -e "s,/[^/]*$,:," -e 's,work/[^/]*/,${WRKSRC}/,' | tr -d \\n
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/gst-libs/gst/tag:${WRKSRC}/output/gst-libs/gst/fft:${WRKSRC}/output/gst-libs/gst/video:${WRKSRC}/output/gst-libs/gst/audio:${WRKSRC}/output/gst-libs/gst/rtp:${WRKSRC}/output/gst-libs/gst/sdp:${WRKSRC}/output/gst-libs/gst/rtsp:${WRKSRC}/output/gst-libs/gst/pbutils:${WRKSRC}/output/gst-libs/gst/riff:${WRKSRC}/output/gst-libs/gst/app:${WRKSRC}/output/gst-libs/gst/allocators:${WRKSRC}/output/gst-libs/gst/gl:${WRKSRC}/output/gst/adder:${WRKSRC}/output/gst/app:${WRKSRC}/output/gst/audioconvert:${WRKSRC}/output/gst/audiomixer:${WRKSRC}/output/gst/audiorate:${WRKSRC}/output/gst/audioresample:${WRKSRC}/output/gst/audiotestsrc:${WRKSRC}/output/gst/compositor:${WRKSRC}/output/gst/encoding:${WRKSRC}/output/gst/gio:${WRKSRC}/output/gst/overlaycomposition:${WRKSRC}/output/gst/pbtypes:${WRKSRC}/output/gst/playback:${WRKSRC}/output/gst/rawparse:${WRKSRC}/output/gst/subparse:${WRKSRC}/output/gst/tcp:${WRKSRC}/output/gst/typefind:${WRKSRC}/output/gst/videoconvert:${WRKSRC}/output/gst/videorate:${WRKSRC}/output/gst/videoscale:${WRKSRC}/output/gst/videotestsrc:${WRKSRC}/output/gst/volume:${WRKSRC}/output/ext/cdparanoia:${WRKSRC}/output/ext/gl:${WRKSRC}/output/ext/libvisual:${WRKSRC}/output/ext/ogg:${WRKSRC}/output/ext/opus:${WRKSRC}/output/ext/pango:${WRKSRC}/output/ext/theora:${WRKSRC}/output/ext/vorbis:${WRKSRC}/output/sys/ximage:${WRKSRC}/output/sys/xvimage:${WRKSRC}/output/tests/examples/device-provider

# test status as of 1.18.5
#Ok:                 88
#Expected Fail:      0
#Fail:               14
#Unexpected Pass:    0
#Skipped:            14
#Timeout:            0

.include "Makefile.common"
BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
