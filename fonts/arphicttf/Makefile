# $NetBSD: Makefile,v 1.4 2002/02/18 11:23:54 rxg Exp $
#

DISTNAME=	arphicttf-2.11
CATEGORIES=	chinese fonts
MASTER_SITES=	ftp://linux.cis.nctu.edu.tw/chinese/fonts/arphic/font/ \
		ftp://linux.cis.nctu.edu.tw/chinese/fonts/arphic/license/ENGLISH/ \
		ftp://linux.cis.nctu.edu.tw/chinese/fonts/arphic/
DISTFILES=	${FONT_SETS} ${MISC_FILES}

MAINTAINER=	rxg@ms25.url.com.tw
COMMENT=	Chinese Big5/GB TrueType fonts made by Arphic Technology

DEPENDS+=	mkttfdir>=1.2:../../fonts/mkttfdir

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

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_DATA_DIR} ${FONTDIR}
	for f in ${FONT_SETS}; do \
		${INSTALL_DATA} ${_DISTDIR}/$$f ${FONTDIR}; \
		${GUNZIP_CMD} ${FONTDIR}/$$f; \
	done

post-install:
.if defined(TTF_TYPE) && (${TTF_TYPE} == "freetype")
	${SH} ${LOCALBASE}/bin/mkttfdir --freetype ${FONTDIR}
.else
	${SH} ${LOCALBASE}/bin/mkttfdir ${FONTDIR}
.endif

.include "../../mk/bsd.pkg.mk"
