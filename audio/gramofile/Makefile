# $NetBSD: Makefile,v 1.18 2015/08/18 07:31:01 wiz Exp $
#

DISTNAME=	gramofile-1.6
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://www.opensourcepartners.nl/~costar/gramofile/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.opensourcepartners.nl/~costar/gramofile/
COMMENT=	Tool for ripping audio from vinyl

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
SUBST_STAGE.snd=	post-patch
SUBST_FILES.snd=	bplaysrc/sndfunc.c
SUBST_SED.snd=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_MESSAGE.snd=	Fixing harcoded audio device.

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
