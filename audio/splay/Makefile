# $NetBSD: Makefile,v 1.13 2002/08/05 17:39:16 wiz Exp $
#

DISTNAME=		splay-0.8.2
CATEGORIES=		audio
MASTER_SITES=		# empty

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://splay.sourceforge.net/
COMMENT=		Audio player/decoder that decodes MPEG Layer I,II,III and WAV files

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--without-xsplay --without-pthread
LIBS+=			-lossaudio

.include "../../mk/bsd.pkg.mk"
