# $NetBSD: Makefile,v 1.5 2004/10/03 00:13:06 tv Exp $
#

DISTNAME=	gramofile-1.6
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://panic.et.tudelft.nl/~costar/gramofile/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://panic.et.tudelft.nl/~costar/gramofile/
COMMENT=	Tool for ripping audio from vinyl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

ALL_TARGET=	gramofile makebplay

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gramofile ${PREFIX}/bin/gramofile
	${INSTALL_PROGRAM} ${WRKSRC}/bplaysrc/bplay ${PREFIX}/bin/bplay_gramo
	cd ${PREFIX}/bin && ${LN} -s bplay_gramo brec_gramo

SUBST_CLASSES=		snd
SUBST_STAGE.snd=	post-patch
SUBST_FILES.snd=	bplaysrc/sndfunc.c
SUBST_SED.snd=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_MESSAGE.snd=	"Fixing harcoded audio device."

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
