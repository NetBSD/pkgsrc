# $NetBSD: Makefile,v 1.9 2006/12/18 01:35:35 wiz Exp $
#

DISTNAME=		tuxnes-0.75
PKGREVISION=		2
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tuxnes/}

MAINTAINER=		pkgsrc-users@NetBSD.org
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
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
