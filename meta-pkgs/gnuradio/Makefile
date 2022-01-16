# $NetBSD: Makefile,v 1.25 2022/01/16 18:06:28 tnn Exp $

META_PACKAGE=	yes

.include	"../../ham/gnuradio-core/version.mk"

DISTNAME=	gnuradio-${VERSION}
CATEGORIES=	meta-pkgs ham
MASTER_SITES=	# empty
DISTFILES=	# empty
LICENSE=	gnu-gpl-v3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/gnuradio/
COMMENT=	Collection of GNU Radio (meta package, easy to install whole thing)

DEPENDS+=	gnuradio-channels-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-channels
DEPENDS+=	gnuradio-network-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-network
DEPENDS+=	gnuradio-companion-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-companion
DEPENDS+=	gnuradio-core-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-core
DEPENDS+=	gnuradio-ctrlport-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-ctrlport
DEPENDS+=	gnuradio-digital-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-digital
DEPENDS+=	gnuradio-doxygen-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-doxygen
DEPENDS+=	gnuradio-dtv-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-dtv
DEPENDS+=	gnuradio-fec-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-fec
DEPENDS+=	gnuradio-pdu-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-pdu
DEPENDS+=	gnuradio-qtgui-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-qtgui
DEPENDS+=	gnuradio-soapy-sdr-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-soapy-sdr
DEPENDS+=	gnuradio-trellis-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-trellis
DEPENDS+=	gnuradio-uhd-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-uhd
DEPENDS+=	gnuradio-utils-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-utils
DEPENDS+=	gnuradio-video-sdl-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-video-sdl
DEPENDS+=	gnuradio-vocoder-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-vocoder
DEPENDS+=	gnuradio-wavelet-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-wavelet
DEPENDS+=	gnuradio-zeromq-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-zeromq

.include "../../mk/bsd.pkg.mk"
