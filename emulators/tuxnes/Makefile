# $NetBSD: Makefile,v 1.5 2005/06/01 18:02:48 jlam Exp $
#

DISTNAME=		tuxnes-0.75
PKGREVISION=	1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tuxnes/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://tuxnes.sourceforge.net/
COMMENT=		NES emulator

ONLY_FOR_PLATFORM=	*-*-i386

USE_TOOLS+=		gmake
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
