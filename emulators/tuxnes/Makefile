# $NetBSD: Makefile,v 1.1.1.1 2004/07/19 20:29:37 wiz Exp $
#

DISTNAME=		tuxnes-0.75
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tuxnes/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://tuxnes.sourceforge.net/
COMMENT=		NES emulator

ONLY_FOR_PLATFORM=	*-*-i386

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes
GNU_CONFIGURE=		yes

SUBST_CLASSES+=		dsp
SUBST_STAGE.dsp=	post-patch
SUBST_MESSAGE.dsp=	Adjusting sound device path.
SUBST_FILES.dsp=	consts.h
SUBST_SED.dsp=		-e "s|/dev/dsp|${DEVOSSAUDIO}|"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tuxnes
.for doc in AUTHORS BUGS COPYING README THANKS
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/tuxnes
.endfor

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
