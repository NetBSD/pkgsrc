# $NetBSD: Makefile,v 1.2.2.2 2002/06/23 18:45:42 jlam Exp $
#

DISTNAME=	arphic-ttf-2.11
CATEGORIES=	fonts
MASTER_SITES=	ftp://linux.cis.nctu.edu.tw/chinese/fonts/arphic/font/ \
		ftp://linux.cis.nctu.edu.tw/chinese/fonts/arphic/license/ENGLISH/ \
		ftp://linux.cis.nctu.edu.tw/chinese/fonts/arphic/
DISTFILES=	${FONT_FILES} ${MISC_FILES}

MAINTAINER=	rxg@ms25.url.com.tw
COMMENT=	Chinese TrueType fonts from Arphic Technology

FONT_FILES=	bkai00mp.ttf.gz bsmi00lp.ttf.gz gbsn00lp.ttf.gz gkai00mp.ttf.gz
MISC_FILES=	ARPHICPL.TXT logo.gif release.txt

DIST_SUBDIR=	arphic-ttf

CONFLICTS=	arphicttf-*

EXTRACT_ONLY=	# empty
WRKSRC=		${WRKDIR}
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_X11BASE=	yes
FONTDIR=	${PREFIX}/lib/X11/fonts/TrueType
DOCDIR=		${PREFIX}/share/doc/arphic-ttf

do-install:
	${INSTALL_DATA_DIR} ${FONTDIR}
	for f in ${FONT_FILES}; do \
		${INSTALL_DATA} ${_DISTDIR}/$$f ${FONTDIR}; \
		${GUNZIP_CMD} ${FONTDIR}/$$f; \
	done
	${INSTALL_DATA_DIR} ${DOCDIR}
	for f in ${MISC_FILES}; do \
		${INSTALL_DATA} ${_DISTDIR}/$$f ${DOCDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
