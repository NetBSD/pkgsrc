# $NetBSD: Makefile,v 1.1.1.1 2001/03/19 19:35:51 wiz Exp $

DISTNAME=	gmodplay-0.08
CATEGORIES=	audio
MASTER_SITES=	http://magic.metawire.com/~rani/ \
		http://rani.free.fr/

MAINTAINER=	collver@linuxfreemail.com
HOMEPAGE=	http://rani.free.fr
COMMENT=	MOD player for IT XM S3M MOD MTM STM FAR ULT 669 AMS DBM MDL OKT files

DEPENDS+=	libslang>=1.4.4:../../devel/libslang
DEPENDS+=	glib>=1.1:../../devel/glib

# only runs correctly on little-endian machines
ONLY_FOR_PLATFORM=	*-*-alpha *-*-arc *-*-cobalt *-*-dreamcast \
			*-*-hpcmips *-*-hpcsh *-*-i386 *-*-pc532 *-*-pmax \
			*-*-vax

USE_GMAKE=	yes
# for libslang
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lossaudio -lcurses

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gmodplay ${PREFIX}/bin/gmodplay
	${INSTALL_SCRIPT} ${FILESDIR}/mod2wav ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gmodplay
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gmodplay

.include "../../mk/bsd.pkg.mk"
