# $NetBSD: Makefile,v 1.6 2003/04/17 14:31:54 salo Exp $
#

DISTNAME=	arphic-ttf-2.11
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/${DIST_SUBDIR}/
DISTFILES=	${FONT_FILES} ${MISC_FILES}

MAINTAINER=	rxg@ms25.url.com.tw
COMMENT=	Chinese TrueType fonts from Arphic Technology

CONFLICTS=	arphicttf-*

FONT_FILES=	bkai00mp.ttf.gz bsmi00lp.ttf.gz gbsn00lp.ttf.gz gkai00mp.ttf.gz
MISC_FILES=	ARPHICPL.TXT logo.gif release.txt

DIST_SUBDIR=	arphic-ttf
EXTRACT_ONLY=	# empty

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

FONTS_TTF_DIRS=	${PREFIX}/lib/X11/fonts/TrueType
DOCDIR=		${PREFIX}/share/doc/arphic-ttf

do-install:
	${INSTALL_DATA_DIR} ${FONTS_TTF_DIRS}
	for f in ${FONT_FILES}; do \
		${INSTALL_DATA} ${_DISTDIR}/$$f ${FONTS_TTF_DIRS}; \
		${GUNZIP_CMD} ${FONTS_TTF_DIRS}/$$f; \
	done
	${INSTALL_DATA_DIR} ${DOCDIR}
	for f in ${MISC_FILES}; do \
		${INSTALL_DATA} ${_DISTDIR}/$$f ${DOCDIR}; \
	done

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
