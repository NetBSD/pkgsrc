# $NetBSD: Makefile,v 1.11 2001/02/16 13:30:50 wiz Exp $
# FreeBSD Id: Makefile,v 1.4 1997/08/09 23:37:33 fenner Exp 
#

DISTNAME=		splay-0.8.2
CATEGORIES=		audio
MASTER_SITES=		http://my.netian.com/~polarb/ \
			http://synergy.kaist.ac.kr/~jwj95/ \
			ftp://ftp.univie.ac.at/systems/linux/linuxberg/files/x11/media/ \
			ftp://ftp.tu-clausthal.de/pub/unix.new/audio/ \
			ftp://ftp.online.be/raid/linuxberg/files/x11/media/ \
			ftp://crydee.sai.msu.ru/zeus/unix/sound/players/ \
			ftp://ftp.cit.nepean.uws.edu.au/unix/misc/audio/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://splay.sourceforge.net/
COMMENT=		Audio player/decoder that decodes MPEG Layer I,II,III and WAV files

# endian and alignment issues
NOT_FOR_PLATFORM=      *-*-sparc *-*-m68k *-*-macppc *-*-sparc64

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--without-xsplay --without-pthread
CONFIGURE_ENV=		LIBS="${LIBS} -lossaudio"

.include "../../mk/bsd.pkg.mk"
