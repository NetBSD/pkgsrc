# $NetBSD: Makefile,v 1.22 2021/05/20 19:24:15 nia Exp $
#

DISTNAME=	gramofile-1.6P
CATEGORIES=	audio
MASTER_SITES=	https://www.opensourcepartners.nl/~costar/gramofile/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.opensourcepartners.nl/~costar/gramofile/
COMMENT=	Tool for ripping audio from vinyl
LICENSE=	gnu-gpl-v2

BUILD_TARGET=	gramofile makebplay

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gramofile \
		${DESTDIR}${PREFIX}/bin/gramofile
	${INSTALL_PROGRAM} ${WRKSRC}/bplaysrc/bplay \
		${DESTDIR}${PREFIX}/bin/bplay_gramo
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -s bplay_gramo brec_gramo

SUBST_CLASSES+=		snd
SUBST_STAGE.snd=	pre-configure
SUBST_FILES.snd=	bplaysrc/sndfunc.c
SUBST_SED.snd=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_MESSAGE.snd=	Fixing harcoded audio device.

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
