# $NetBSD: Makefile,v 1.14 2003/06/02 01:21:33 jschauma Exp $
#

DISTNAME=		splay-0.8.2
CATEGORIES=		audio
MASTER_SITES=		# empty

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://splay.sourceforge.net/
COMMENT=		Audio player/decoder that decodes MPEG Layer I,II,III and WAV files

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--without-xsplay --without-pthread
LIBS+=			-lossaudio

.include "../../mk/bsd.pkg.mk"
