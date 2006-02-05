# $NetBSD: Makefile,v 1.15 2006/02/05 23:09:08 joerg Exp $
#

DISTNAME=	arphic-ttf-2.11
PKGREVISION=	4
CATEGORIES=	fonts
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/keith/zh-arphicttf/
DISTFILES=	${FONT_FILES} ${MISC_FILES}

MAINTAINER=	rxg@NetBSD.org
COMMENT=	Chinese TrueType fonts from Arphic Technology

CONFLICTS=	arphicttf-*

FONT_FILES=	bkai00mp.ttf.gz bsmi00lp.ttf.gz gbsn00lp.ttf.gz gkai00mp.ttf.gz
MISC_FILES=	ARPHICPL.TXT logo.gif release.txt

DIST_SUBDIR=	arphic-ttf
EXTRACT_ONLY=	# empty

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

USE_TOOLS+=	gunzip

FONTS_DIRS.ttf=	${PREFIX}/lib/X11/fonts/TTF
DOCDIR=		${PREFIX}/share/doc/arphic-ttf

do-install:
	${INSTALL_DATA_DIR} ${FONTS_DIRS.ttf}
	for f in ${FONT_FILES}; do \
		${INSTALL_DATA} ${_DISTDIR}/$$f ${FONTS_DIRS.ttf}; \
		${GUNZIP_CMD} ${FONTS_DIRS.ttf}/$$f; \
	done
	${INSTALL_DATA_DIR} ${DOCDIR}
	for f in ${MISC_FILES}; do \
		${INSTALL_DATA} ${_DISTDIR}/$$f ${DOCDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
