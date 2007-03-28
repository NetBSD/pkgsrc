# $NetBSD: Makefile,v 1.14 2007/03/28 13:20:47 joerg Exp $
#

DISTNAME=		fceu-0.98.13.src
PKGNAME=		${DISTNAME:S/.src//}
PKGREVISION=		3
CATEGORIES=		emulators
MASTER_SITES=		http://pdaxrom.theinternet.nl/fceu/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://pdaxrom.theinternet.nl/fceu/
COMMENT=		Portable NES and Famicom emulator

WRKSRC=			${WRKDIR}/fceu
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

SUBST_CLASSES+=		dsp
SUBST_STAGE.dsp=	post-patch
SUBST_MESSAGE.dsp=	Adjusting sound device path.
SUBST_FILES.dsp=	src/drivers/sexyal/drivers/oss.c
SUBST_SED.dsp=		-e "s|/dev/dsp|${DEVOSSAUDIO}|"

INSTALLATION_DIRS=	${PKGMANDIR}/man6 share/doc/fceu

post-install:
	${INSTALL_DATA} ${WRKSRC}/Documentation/fceu-sdl.6 \
		${PREFIX}/${PKGMANDIR}/man6/fceu.6
	${INSTALL_DATA} ${WRKSRC}/Documentation/*.html \
		${PREFIX}/share/doc/fceu
	${INSTALL_DATA} ${WRKSRC}/Documentation/*.txt \
		${PREFIX}/share/doc/fceu

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
