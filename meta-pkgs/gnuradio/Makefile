# $NetBSD: Makefile,v 1.16 2016/06/16 14:05:38 mef Exp $

META_PACKAGE=	yes

.include	"../../ham/gnuradio-core/Makefile.version"

DISTNAME=       gnuradio-${VERSION}
CATEGORIES=	meta-pkgs ham
MASTER_SITES=	# empty
DISTFILES=	# empty
LICENSE=	gnu-gpl-v3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gnuradio/
COMMENT=	Collection of GNU Radio (meta package, easy to install whole thing)

# 20 package for now
DEPENDS+=	gnuradio-atsc-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-atsc
DEPENDS+=	gnuradio-channels-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-channels
DEPENDS+=	gnuradio-companion-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-companion
DEPENDS+=	gnuradio-core-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-core
DEPENDS+=	gnuradio-ctrlport-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-ctrlport

DEPENDS+=	gnuradio-digital-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-digital
# dropped, for unstable with doxygen update
#EPENDS+=	gnuradio-doxygen-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-doxygen
DEPENDS+=	gnuradio-dtv-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-dtv
DEPENDS+=	gnuradio-fcd-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-fcd
DEPENDS+=	gnuradio-fec-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-fec

DEPENDS+=	gnuradio-noaa-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-noaa
DEPENDS+=	gnuradio-pager-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-pager
DEPENDS+=	gnuradio-qtgui-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-qtgui
DEPENDS+=	gnuradio-trellis-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-trellis
DEPENDS+=	gnuradio-uhd-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-uhd

DEPENDS+=	gnuradio-utils-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-utils
DEPENDS+=	gnuradio-video-sdl-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-video-sdl
DEPENDS+=	gnuradio-vocoder-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-vocoder
DEPENDS+=	gnuradio-wavelet-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-wavelet
DEPENDS+=	gnuradio-wxgui-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-wxgui

DEPENDS+=	gnuradio-zeromq-${VERSION}{,nb[0-9]*}:../../ham/gnuradio-zeromq

.include "../../mk/bsd.pkg.mk"
