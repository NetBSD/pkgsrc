# $NetBSD: Makefile,v 1.17 2004/04/18 14:34:19 ben Exp $

DISTNAME=	gmodplay-0.08
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://magic.metawire.com/~rani/ \
		http://rani.free.fr/

MAINTAINER=	ben@NetBSD.org
HOMEPAGE=	http://rani.free.fr/
COMMENT=	MOD player for IT XM S3M MOD MTM STM FAR ULT 669 AMS DBM MDL OKT files

# only runs correctly on little-endian machines
ONLY_FOR_PLATFORM=	*-*-alpha *-*-arc *-*-cobalt *-*-dreamcast \
			*-*-hpcmips *-*-hpcsh *-*-i386 *-*-pc532 *-*-pmax \
			*-*-vax

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++

# for libslang and ossaudio
CFLAGS+=	-DAUDIO_DEV="\"\\\"$(DEVOSSAUDIO)\\\"\""
LDFLAGS+=	${LIBOSSAUDIO}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
LDFLAGS+=	-lcurses
.endif

.if ${OPSYS} == "Linux"
LDFLAGS+=	-lncurses -ldl
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gmodplay ${PREFIX}/bin/gmodplay
	${INSTALL_SCRIPT} ${FILESDIR}/mod2wav ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gmodplay
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gmodplay

.include "../../devel/libslang/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
