# $NetBSD: Makefile,v 1.4 2004/10/03 00:14:40 tv Exp $
#

DISTNAME=		fceu-0.98.11.src
PKGNAME=		${DISTNAME:S/.src//}
PKGREVISION=	1
CATEGORIES=		emulators
MASTER_SITES=		http://fceultra.sourceforge.net/releases/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://fceultra.sourceforge.net/
COMMENT=		Portable NES and Famicom emulator

WRKSRC=			${WRKDIR}/fceu
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

SUBST_CLASSES+=		dsp
SUBST_STAGE.dsp=	post-patch
SUBST_MESSAGE.dsp=	Adjusting sound device path.
SUBST_FILES.dsp=	src/drivers/sexyal/drivers/oss.c
SUBST_SED.dsp=		-e "s|/dev/dsp|${DEVOSSAUDIO}|"

post-install:
	${INSTALL_DATA} ${WRKSRC}/Documentation/fceu-sdl.6 \
		${PREFIX}/man/man6/fceu.6
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fceu
	${INSTALL_DATA} ${WRKSRC}/Documentation/*.html \
		${PREFIX}/share/doc/fceu
	${INSTALL_DATA} ${WRKSRC}/Documentation/*.txt \
		${PREFIX}/share/doc/fceu

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
