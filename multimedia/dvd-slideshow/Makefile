# $NetBSD: Makefile,v 1.22 2020/04/23 15:07:46 nia Exp $

DISTNAME=	dvd-slideshow-0.7.5
PKGREVISION=	13
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dvd-slideshow/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://dvd-slideshow.sourceforge.net/
COMMENT=	Script that creates a slideshow-style DVD with some simple menus

DEPENDS+=	cdrtools-[0-9]*:../../sysutils/cdrtools
DEPENDS+=	lame-[0-9]*:../../audio/lame
DEPENDS+=	vorbis-tools-[0-9]*:../../audio/vorbis-tools
DEPENDS+=	sox-[0-9]*:../../audio/sox
DEPENDS+=	dvdauthor-[0-9]*:../../multimedia/dvdauthor
DEPENDS+=	dvd+rw-tools-[0-9]*:../../sysutils/dvd+rw-tools
DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
# uses programs only (mplex, ffmpeg)
DEPENDS+=	mjpegtools-[0-9]*:../../multimedia/mjpegtools
DEPENDS+=	ffmpeg4-[0-9]*:../../multimedia/ffmpeg4

USE_TOOLS+=	bash:run
NO_BUILD=	yes
SCRIPTS=	dvd-slideshow dvd-menu dir2slideshow gallery1-to-slideshow \
			jigl2slideshow
DOC_FILES=	changelog.html gallery1-to-slideshow.html \
			dir2slideshow.html jigl2slideshow.html \
			dvd-menu.html dvd-slideshow.html
MAN1=		dvd-slideshow.1 dvd-menu.1 dir2slideshow.1 gallery1-to-slideshow.1 \
			jigl2slideshow.1

REPLACE_BASH =	dir2slideshow dvd-burn dvd-encode dvd-iso dvd-menu \
				dvd-slideshow dvd-slideshow.orig gallery1-to-slideshow \
				install.sh jigl2slideshow

SUBST_CLASSES+=		fonts
SUBST_STAGE.fonts=	post-configure
SUBST_FILES.fonts=	dvd-menu dvd-slideshow
SUBST_SED.fonts=	-e 's,/usr/share/fonts/,${PREFIX}/share/fonts/,g'
SUBST_MESSAGE.fonts=	Fixing hardcoded fonts paths.

SUBST_CLASSES+=		pipeline
SUBST_STAGE.pipeline=	post-configure
SUBST_FILES.pipeline=	dvd-slideshow
SUBST_SED.pipeline=	-e 's/print0/printx/g;s/sort -z/sort/g;s/xargs -0/xargs/g'
SUBST_MESSAGE.pipeline=	Fixing Linux centric pipeline.

SUBST_CLASSES+=			lsof
SUBST_STAGE.lsof=		post-configure
SUBST_FILES.lsof=		dvd-slideshow
SUBST_SED.lsof=			-e 's+/usr/sbin/lsof+${DESTDIR}${PREFIX}/sbin/lsof+g'
SUBST_MESSAGE.lsof=		Fixing lsof command line

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/dvd-slideshow

do-install:
.for file in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/bin
.endfor
.for file in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/${file} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endfor
	${INSTALL_DATA} ${WRKSRC}/dvd-slideshowrc ${DESTDIR}${PREFIX}/share/doc/dvd-slideshow
.for file in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DESTDIR}${PREFIX}/share/doc/dvd-slideshow
.endfor

.include "../../mk/bsd.pkg.mk"
