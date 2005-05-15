# $NetBSD: Makefile,v 1.9 2005/05/15 22:02:27 jlam Exp $
#

DISTNAME=	baekmuk-2.0
PKGNAME=	ko-baekmuk-20010718
PKGREVISION=	3
CATEGORIES=	fonts x11 korean
MASTER_SITES+=	ftp://ftp.mizi.com/pub/baekmuk/ \
		http://zinc.skku.ac.kr/~wkpark/baekmuk/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	X11 fonts for KSX 1001 Korean standard (baekmuk foundry)

CONFLICTS+=	ksc5601fonts-[0-9]*

USE_X11BASE=	yes
USE_TOOLS+=	gzip

MAKE_ENV+=	FONTDIR=${FONTDIR} GZIP_CMD="${GZIP_CMD}"

# fonts
BAEKMUK_BDF=	batang10.bdf batang10b.bdf batang12.bdf batang12b.bdf \
		batang14.bdf batang14b.bdf batang16.bdf batang16b.bdf \
		batang18.bdf batang18b.bdf batang20.bdf batang20b.bdf \
		batang24.bdf batang24b.bdf dotum10.bdf dotum12.bdf dotum14.bdf \
		dotum16.bdf dotum18.bdf dotum20.bdf dotum24.bdf gulim10.bdf \
		gulim10b.bdf gulim12.bdf gulim12b.bdf gulim14.bdf gulim14b.bdf \
		gulim16.bdf gulim16b.bdf gulim18.bdf gulim18b.bdf gulim20.bdf \
		gulim20b.bdf gulim24.bdf gulim24b.bdf hline10.bdf hline12.bdf \
		hline14.bdf hline16.bdf hline18.bdf hline20.bdf hline24.bdf

FONTDIR=${PREFIX}/lib/X11/fonts/local

post-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${.CURDIR}/../../fonts/ko-x11fonts/files/Makefile ${WRKSRC}
	(cd ${WRKSRC}; ${MAKE} prepare)

pre-install:
	[ -d ${FONTDIR} ] || ${INSTALL_DATA_DIR} ${FONTDIR}
	cp ${WRKSRC}/../fonts.alias ${FONTDIR}

post-install:
	(cd ${FONTDIR}; mkfontdir)

.include "../../mk/bsd.pkg.mk"
