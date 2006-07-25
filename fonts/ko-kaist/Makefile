# $NetBSD: Makefile,v 1.12 2006/07/25 15:12:27 jlam Exp $
#

DISTNAME=	ko-kaist-20010718
PKGREVISION=	1
CATEGORIES=	fonts x11 korean
MASTER_SITES+=	ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/
DISTFILES=	kaist-newmj18.bdf.gz ks_philgi16.bdf.gz \
		kaist-newmj16.bdf.gz ks_iyagi16.bdf.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	X11 fonts for Korean KSC 5601 standard (kaist foundry)

CONFLICTS+=	ksc5601fonts-[0-9]*

USE_X11BASE=		yes
USE_TOOLS+=		gzip gunzip
EXTRACT_ONLY=		# empty

MAKE_ENV+=	FONTDIR=${FONTDIR:Q} GZIP_CMD=${GZIP_CMD:Q}

FONTDIR=	${PREFIX}/lib/X11/fonts/local
FONTS_DIRS.x11=	${FONTDIR}

do-extract:
	${MKDIR} ${WRKSRC}
	for i in ${DISTFILES}; do \
		${CP} ${_DISTDIR}$$i ${WRKDIR}; ${GUNZIP_CMD} ${WRKDIR}/$$i; \
	done
	${CP} ${.CURDIR}/../../fonts/ko-x11fonts/files/Makefile ${WRKSRC}

do-configure:
	cd ${WRKSRC}; ${MAKE} prepare

pre-install:
	[ -d ${FONTDIR} ] || ${INSTALL_DATA_DIR} ${FONTDIR}

.include "../../mk/bsd.pkg.mk"
