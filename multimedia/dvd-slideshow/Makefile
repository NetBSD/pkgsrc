# $NetBSD: Makefile,v 1.1 2007/12/28 20:30:47 darcy Exp $
# FreeBSD Id: ports/multimedia/dvd-slideshow/Makefile,v 1.12 2007/09/23 04:42:06 edwin Exp

DISTNAME=	dvd-slideshow-0.7.5
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=${PORTNAME}/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://dvd-slideshow.sourceforge.net/
COMMENT=	Script that creates a slideshow-style DVD with some simple menus

DEPENDS +=	cdrtools:../../sysutils/cdrtools
DEPENDS +=	sox:../../audio/sox
DEPENDS +=	dvdauthor:../../multimedia/dvdauthor
DEPENDS +=	dvd+rw-tools:../../sysutils/dvd+rw-tools

USE_X11BASE=yes
USE_TOOLS += bash
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

.include "../../mk/bsd.prefs.mk"

.if exists(${LOCALBASE}/bin/lame)
DEPENDS+=	lame:../../audio/lame
.endif
.if exists(${LOCALBASE}/bin/oggdec)
DEPENDS +=	vorbis-tools:../../audio/vorbis-tools
.endif

SUBST_CLASSES+=     	fonts
SUBST_STAGE.fonts=  	post-install
SUBST_FILES.fonts=  	dvd-menu dvd-slideshow
SUBST_SED.fonts= 	   -e 's,/usr/share/fonts/,${X11BASE}/lib/X11/fonts/,g'
SUBST_MESSAGE.fonts=    Fixing hardcoded fonts paths.

do-install:
.for file in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor

	@${ECHO_MSG} "Installing man files."
.for file in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/${file} ${PREFIX}/${PKGMANDIR}/man1
.endfor

	@${ECHO_MSG} "Installing doc files."
	${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/dvd-slideshowrc ${DOCDIR}
.for file in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCDIR}
.endfor

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../multimedia/mjpegtools/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
