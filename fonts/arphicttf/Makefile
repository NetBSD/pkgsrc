# $NetBSD: Makefile,v 1.3 2001/11/29 17:37:57 wiz Exp $
#

DISTNAME=	arphicttf-2.11
CATEGORIES=	chinese fonts
MASTER_SITES=	ftp://linux.cis.nctu.edu.tw/chinese/fonts/arphic/font/ \
		ftp://linux.cis.nctu.edu.tw/chinese/fonts/arphic/license/ENGLISH/ \
		ftp://linux.cis.nctu.edu.tw/chinese/fonts/arphic/
DISTFILES=	${FONT_SETS} ${MISC_FILES}

MAINTAINER=	rxg@ms25.url.com.tw
COMMENT=	Chinese Big5/GB TrueType fonts made by Arphic Technology

DEPENDS+=	mkttfdir>=1.1nb1:../../fonts/mkttfdir

FONT_SETS=	bkai00mp.ttf.gz \
		bsmi00lp.ttf.gz \
		gbsn00lp.ttf.gz \
		gkai00mp.ttf.gz

MISC_FILES=	ARPHICPL.TXT logo.gif release.txt

DIST_SUBDIR=	${PKGNAME}

EXTRACT_ONLY=	# empty
WRKSRC=		${WRKDIR}
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_X11BASE=	yes
FONTDIR=	${PREFIX}/lib/X11/fonts/TrueType

do-install:
	${INSTALL_DATA_DIR} ${FONTDIR}
	for f in ${FONT_SETS}; do \
		${INSTALL_DATA} ${_DISTDIR}/$$f ${FONTDIR}; \
		${GUNZIP_CMD} ${FONTDIR}/$$f; \
	done

post-install:
	${SH} ${LOCALBASE}/bin/mkttfdir ${FONTDIR}

.include "../../mk/bsd.pkg.mk"
