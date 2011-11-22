# $NetBSD: Makefile,v 1.22 2011/11/22 16:37:01 marino Exp $

DISTNAME=	maplay1_2
PKGNAME=	maplay-1.2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cs.tu-berlin.de/pub/misc/maplay1.2/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	MPEG audio player/decoder for layer I and II MPEG audio streams

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}

USE_LANGUAGES=	c++
NOT_FOR_PLATFORM=	Interix-*-*

INSTALLATION_DIRS=	bin

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "DragonFly"
SUBST_CLASSES+=		iostream iomanip
SUBST_STAGE.iostream=	post-patch
SUBST_STAGE.iomanip=	post-patch
SUBST_FILES.iostream=	obuffer.h synthesis_filter.h \
			ulaw.cc crc.cc ibitstream.cc obuffer.cc \
			subband_layer_1.cc subband_layer_2.cc \
			scalefactors.cc synthesis_filter.cc \
			header.cc maplay.cc
SUBST_FILES.iomanip=	header.cc maplay.cc
SUBST_SED.iostream=	-e 's,<iostream.h>,<iostream>,' \
			-e 's,cerr,std::cerr,g'
SUBST_SED.iomanip=	-e 's,<iomanip.h>,<iomanip>,'
SUBST_MESSAGE.iostream=	Fixing old iostream headers includes
SUBST_MESSAGE.iomanip=	Fixing old iomanip headers includes
.endif

pre-configure:
	cd ${WRKSRC} && ${MAKE} pre-install

.include "../../mk/bsd.pkg.mk"
