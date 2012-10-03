# $NetBSD: Makefile,v 1.12 2012/10/03 18:28:26 asau Exp $
#

DISTNAME=	hanyang-font-pcf
PKGNAME=	ko-hanyang-20010718
PKGREVISION=	1
CATEGORIES=	fonts x11 korean
MASTER_SITES+=	ftp://ftp.kaist.ac.kr/pub/hangul/fonts/ \
		ftp://ftp.kreonet.re.kr/pub/hangul/cair-archive/fonts/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	X11 fonts for KSC 5601 standard

CONFLICTS+=	ksc5601fonts-[0-9]*

USE_X11BASE=	yes
USE_TOOLS+=	gzip
EXTRACT_ONLY=	# empty

MAKE_ENV+=	FONTDIR=${DESTDIR}${FONTDIR:Q} GZIP_CMD=${GZIP_CMD:Q}

# fonts
EXTRACT_ONLY+=	hanyang-font-pcf.tar.gz
HANYANG_PCF=	hgm10.pcf hgm12.pcf hgm14.pcf hgm16.pcf hgm18.pcf hgm20.pcf \
		hmm10.pcf hmm12.pcf hmm14.pcf hmm16.pcf hmm18.pcf hmm20.pcf

FONTDIR=	${PREFIX}/lib/X11/fonts/local
FONTS_DIRS.x11=	${FONTDIR}

post-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${.CURDIR}/../../fonts/ko-x11fonts/files/Makefile ${WRKSRC}

do-configure:
	cd ${WRKSRC}; ${MAKE} prepare

post-build:
	for i in ${HANYANG_PCF}; do \
		${MV} ${WRKDIR}/$$i ${WRKSRC}; \
	done

INSTALLATION_DIRS=	${FONTDIR}

.include "../../mk/bsd.pkg.mk"
