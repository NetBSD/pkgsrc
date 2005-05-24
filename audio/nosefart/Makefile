# $NetBSD: Makefile,v 1.6 2005/05/24 13:46:21 rillig Exp $

DISTNAME=		nosefart-2.3-mls
PKGNAME=		${DISTNAME:S/-mls//}
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=nosefart/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dgriffi@cs.csubak.edu
HOMEPAGE=		http://nosefart.sourceforge.net/
COMMENT=		Player for NES Sound Format (NSF) files

USE_TOOLS+=		gmake
NO_CONFIGURE=		YES

SUBST_CLASSES+=		ossaudio
SUBST_STAGE.ossaudio=	pre-build
SUBST_MESSAGE.ossaudio=	"Fixing audio device."
SUBST_FILES.ossaudio=	src/linux/main_linux.c
SUBST_SED.ossaudio=	-e 's|/dev/dsp|${DEVOSSSOUND}|'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nsfobj/nosefart ${PREFIX}/bin

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
