# $NetBSD: Makefile,v 1.10 2003/11/25 22:04:03 ben Exp $

DISTNAME=	gmodplay-0.08
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://magic.metawire.com/~rani/ \
		http://rani.free.fr/

MAINTAINER=	collver1@comcast.net
HOMEPAGE=	http://rani.free.fr/
COMMENT=	MOD player for IT XM S3M MOD MTM STM FAR ULT 669 AMS DBM MDL OKT files

# only runs correctly on little-endian machines
ONLY_FOR_PLATFORM=	*-*-alpha *-*-arc *-*-cobalt *-*-dreamcast \
			*-*-hpcmips *-*-hpcsh *-*-i386 *-*-pc532 *-*-pmax \
			*-*-vax

USE_BUILDLINK2=		YES
USE_GMAKE=		YES

# for libslang and ossaudio
CFLAGS+=	-DAUDIO_DEV="\"\\\"$(DEVOSSAUDIO)\\\"\""
LDFLAGS+=	${LIBOSSAUDIO} -lcurses

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gmodplay ${PREFIX}/bin/gmodplay
	${INSTALL_SCRIPT} ${FILESDIR}/mod2wav ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gmodplay
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gmodplay

.include "../../devel/libslang/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
