# $NetBSD: Makefile,v 1.22 2018/12/08 20:32:06 nia Exp $
#

DISTNAME=	arphic-ttf-2.11
PKGREVISION=	6
CATEGORIES=	fonts
MASTER_SITES=	https://ctan.org/tex-archive/fonts/arphic-ttf/
DISTFILES=	${FONT_FILES} ${MISC_FILES}

MAINTAINER=	rxg@NetBSD.org
COMMENT=	Chinese TrueType fonts from Arphic Technology
LICENSE=	arphic-public

CONFLICTS=	arphicttf-[0-9]*

FONT_FILES=	bkai00mp.ttf bsmi00lp.ttf gbsn00lp.ttf gkai00mp.ttf
MISC_FILES=	ARPHICPL.txt release.txt

DIST_SUBDIR=	arphic-ttf
WRKSRC=		${WRKDIR}

NO_CONFIGURE=	YES
NO_BUILD=	YES

FONTS_DIRS.ttf=	${PREFIX}/share/fonts/X11/TTF
DOCDIR=		${PREFIX}/share/doc/arphic-ttf

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTS_DIRS.ttf}
	cd ${WRKSRC} && ${INSTALL_DATA} ${FONT_FILES} \
		${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${MISC_FILES} ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
