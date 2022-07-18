# $NetBSD: Makefile,v 1.20 2022/07/18 15:40:56 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/}
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - bad plugins

USE_TOOLS+=	xgettext

GST_PLUGINS+=	accurip
GST_PLUGINS+=	adpcmdec
GST_PLUGINS+=	adpcmenc
GST_PLUGINS+=	aiff
GST_PLUGINS+=	asfmux
GST_PLUGINS+=	audiobuffersplit
GST_PLUGINS+=	audiofxbad
GST_PLUGINS+=	audiolatency
GST_PLUGINS+=	audiomixmatrix
GST_PLUGINS+=	audiovisualizers
GST_PLUGINS+=	autoconvert
GST_PLUGINS+=	bayer
GST_PLUGINS+=	camerabin2
GST_PLUGINS+=	coloreffects
GST_PLUGINS+=	debugutils
GST_PLUGINS+=	dvbsubenc
GST_PLUGINS+=	dvbsuboverlay
GST_PLUGINS+=	dvdspu
GST_PLUGINS+=	faceoverlay
GST_PLUGINS+=	festival
GST_PLUGINS+=	fieldanalysis
GST_PLUGINS+=	freeverb
GST_PLUGINS+=	frei0r
GST_PLUGINS+=	gaudieffects
GST_PLUGINS+=	gdp
GST_PLUGINS+=	geometrictransform
GST_PLUGINS+=	id3tag
GST_PLUGINS+=	inter
GST_PLUGINS+=	interlace
GST_PLUGINS+=	ivfparse
GST_PLUGINS+=	ivtc
GST_PLUGINS+=	jp2kdecimator
GST_PLUGINS+=	jpegformat
GST_PLUGINS+=	librfb
GST_PLUGINS+=	midi
GST_PLUGINS+=	mpegdemux
GST_PLUGINS+=	mpegpsmux
GST_PLUGINS+=	mpegtsdemux
GST_PLUGINS+=	mpegtsmux
GST_PLUGINS+=	mxf
GST_PLUGINS+=	netsim
GST_PLUGINS+=	onvif
GST_PLUGINS+=	pcapparse
GST_PLUGINS+=	pnm
GST_PLUGINS+=	proxy
GST_PLUGINS+=	rawparse
GST_PLUGINS+=	removesilence
GST_PLUGINS+=	rist
GST_PLUGINS+=	rtmp2
GST_PLUGINS+=	rtp
GST_PLUGINS+=	sdp
GST_PLUGINS+=	segmentclip
GST_PLUGINS+=	siren
GST_PLUGINS+=	smooth
GST_PLUGINS+=	speed
GST_PLUGINS+=	subenc
GST_PLUGINS+=	switchbin
GST_PLUGINS+=	timecode
# XXX: maybe revisit
# XXX: multimedia/gst-plugins1-transcode
GST_PLUGINS+=	transcode
GST_PLUGINS+=	videofilters
GST_PLUGINS+=	videoframe_audiolevel
GST_PLUGINS+=	videoparsers
GST_PLUGINS+=	videosignal
GST_PLUGINS+=	vmnc
GST_PLUGINS+=	y4m

GST_PLUGINS+=	introspection
GST_PLUGINS+=	nls

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "Makefile.common"
BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
