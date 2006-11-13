# $NetBSD: Makefile,v 1.7 2006/11/13 16:19:40 wulf Exp $

.include	"../../meta-pkgs/gnuradio/Makefile.version"

DISTNAME=       gnuradio-${VERSION}
CATEGORIES=	meta-pkgs ham gnuradio
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gnuradio/
COMMENT=	"meta-package" for GNU Radio

DEPENDS+=	gnuradio-core-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-core
DEPENDS+=	gnuradio-core-docs-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-core-docs
DEPENDS+=	gnuradio-audio-jack-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-audio-jack
DEPENDS+=	gnuradio-audio-oss-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-audio-oss
DEPENDS+=	gnuradio-audio-portaudio-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-audio-portaudio
DEPENDS+=	gnuradio-gsm-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-gsm
DEPENDS+=	usrp-${VERSION}{,nb[0-9]*}:../../ham/usrp
DEPENDS+=	usrp-docs-${VERSION}{,nb[0-9]*}:../../ham/usrp-docs
DEPENDS+=	gnuradio-usrp-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-usrp
DEPENDS+=	gnuradio-wxgui-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-wxgui
DEPENDS+=	gnuradio-examples-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-examples
DEPENDS+=	gnuradio-video-sdl-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-video-sdl
DEPENDS+=	gnuradio-trellis-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-trellis
DEPENDS+=	gnuradio-radio-astronomy-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-radio-astronomy
DEPENDS+=	gnuradio-howto-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-howto

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
