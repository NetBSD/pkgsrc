# $NetBSD: Makefile,v 1.17 2015/07/04 16:18:32 joerg Exp $
#

DISTNAME=	ko-kaist-20010718
PKGREVISION=	2
CATEGORIES=	fonts x11 korean
MASTER_SITES+=	ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/
DISTFILES=	kaist-newmj18.bdf.gz ks_philgi16.bdf.gz \
		kaist-newmj16.bdf.gz ks_iyagi16.bdf.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	X11 fonts for Korean KSC 5601 standard (kaist foundry)

CONFLICTS+=	ksc5601fonts-[0-9]*

USE_TOOLS+=		gzip gunzip bdftopcf
EXTRACT_ONLY=		# empty

MAKE_ENV+=	FONTDIR=${DESTDIR}${FONTDIR:Q} GZIP_CMD=${GZIP_CMD:Q}

FONTDIR=	${PREFIX}/share/fonts/X11/local
FONTS_DIRS.x11=	${FONTDIR}

INSTALLATION_DIRS=	${FONTDIR}

do-extract:
	${MKDIR} ${WRKSRC}
	for i in ${DISTFILES}; do \
		${CP} ${_DISTDIR}$$i ${WRKDIR}; ${GUNZIP_CMD} ${WRKDIR}/$$i; \
	done
	${CP} ${.CURDIR}/../../fonts/ko-x11fonts/files/Makefile ${WRKSRC}

do-configure:
	cd ${WRKSRC}; ${MAKE} prepare

.include "../../mk/bsd.pkg.mk"
