# $NetBSD: Makefile,v 1.2 2001/06/26 14:26:55 zuntum Exp $

DISTNAME=	gmodplay-0.08
CATEGORIES=	audio
MASTER_SITES=	http://magic.metawire.com/~rani/ \
		http://rani.free.fr/

MAINTAINER=	collver@linuxfreemail.com
HOMEPAGE=	http://rani.free.fr
COMMENT=	MOD player for IT XM S3M MOD MTM STM FAR ULT 669 AMS DBM MDL OKT files

# only runs correctly on little-endian machines
ONLY_FOR_PLATFORM=	*-*-alpha *-*-arc *-*-cobalt *-*-dreamcast \
			*-*-hpcmips *-*-hpcsh *-*-i386 *-*-pc532 *-*-pmax \
			*-*-vax

USE_BUILDLINK_ONLY=	YES
USE_GMAKE=		YES

# for libslang
LDFLAGS+=	-lossaudio -lcurses

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gmodplay ${PREFIX}/bin/gmodplay
	${INSTALL_SCRIPT} ${FILESDIR}/mod2wav ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gmodplay
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gmodplay

.include "../../devel/libslang/buildlink.mk"
.include "../../devel/glib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
