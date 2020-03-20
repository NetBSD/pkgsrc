# $NetBSD: Makefile,v 1.18 2020/03/20 11:57:36 nia Exp $

DISTNAME=		tuxnes-0.75
PKGREVISION=		4
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tuxnes/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://tuxnes.sourceforge.net/
COMMENT=		NES emulator
LICENSE=		gnu-gpl-v2 # or later

# Uses i386 assembler, and has an i386-targeted dynamic recompiler.
ONLY_FOR_PLATFORM=	*-*-i386

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

SUBST_CLASSES+=		dsp
SUBST_STAGE.dsp=	pre-configure
SUBST_MESSAGE.dsp=	Adjusting sound device path.
SUBST_FILES.dsp=	consts.h
SUBST_SED.dsp=		-e "s|/dev/dsp|${DEVOSSAUDIO}|"

SUBST_CLASSES.SunOS+=	gld
SUBST_STAGE.gld=	pre-configure
SUBST_MESSAGE.gld=	Using GNU ld to create table.o
SUBST_FILES.gld=	Makefile.in
SUBST_SED.gld=		-e "/ld -r/s/ld/gld/"

CPPFLAGS.SunOS+=	-D_XOPEN_SOURCE=500

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/tuxnes
.for doc in AUTHORS BUGS COPYING README THANKS
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DESTDIR}${PREFIX}/share/doc/tuxnes
.endfor

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
