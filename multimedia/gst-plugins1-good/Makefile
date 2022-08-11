# $NetBSD: Makefile,v 1.11 2022/08/11 05:09:05 gutteridge Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/}
PKGREVISION=	1
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - good plugins

USE_TOOLS+=	xgettext

# Feature options for plugins without external deps
GST_PLUGINS+=	alpha
GST_PLUGINS+=	apetag
GST_PLUGINS+=	audiofx
GST_PLUGINS+=	audioparsers
GST_PLUGINS+=	auparse
GST_PLUGINS+=	autodetect
GST_PLUGINS+=	avi
GST_PLUGINS+=	cutter
GST_PLUGINS+=	debugutils
GST_PLUGINS+=	deinterlace
GST_PLUGINS+=	dtmf
GST_PLUGINS+=	effectv
GST_PLUGINS+=	equalizer
GST_PLUGINS+=	flv
GST_PLUGINS+=	flx
GST_PLUGINS+=	goom
GST_PLUGINS+=	goom2k1
GST_PLUGINS+=	icydemux
GST_PLUGINS+=	id3demux
GST_PLUGINS+=	imagefreeze
GST_PLUGINS+=	interleave
GST_PLUGINS+=	isomp4
GST_PLUGINS+=	law
GST_PLUGINS+=	level
GST_PLUGINS+=	matroska
GST_PLUGINS+=	monoscope
GST_PLUGINS+=	multifile
GST_PLUGINS+=	multipart
GST_PLUGINS+=	replaygain
GST_PLUGINS+=	rtp
GST_PLUGINS+=	rtpmanager
GST_PLUGINS+=	rtsp
GST_PLUGINS+=	shapewipe
GST_PLUGINS+=	smpte
GST_PLUGINS+=	spectrum
GST_PLUGINS+=	udp
GST_PLUGINS+=	videobox
GST_PLUGINS+=	videocrop
GST_PLUGINS+=	videofilter
GST_PLUGINS+=	videomixer
GST_PLUGINS+=	wavenc
GST_PLUGINS+=	wavparse
GST_PLUGINS+=	y4m

GST_PLUGINS+=	nls
GST_PLUGINS+=	tests

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
