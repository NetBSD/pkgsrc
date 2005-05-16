# $NetBSD: Makefile,v 1.5 2005/05/16 18:21:42 jlam Exp $
#

DISTNAME=	ko-kaist-20010718
CATEGORIES=	fonts x11 korean
MASTER_SITES+=	ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/
DISTFILES=	kaist-newmj18.bdf.gz ks_philgi16.bdf.gz \
		kaist-newmj16.bdf.gz ks_iyagi16.bdf.gz

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	X11 fonts for Korean KSC 5601 standard (kaist foundry)

CONFLICTS+=	ksc5601fonts-[0-9]*

USE_X11BASE=		yes
PKGSRC_USE_TOOLS+=	gunzip
USE_TOOLS+=		gzip
EXTRACT_ONLY=		# empty

MAKE_ENV+=	FONTDIR=${FONTDIR} GZIP_CMD="${GZIP_CMD}"

FONTDIR=${PREFIX}/lib/X11/fonts/local

do-extract:
	${MKDIR} ${WRKSRC}
	for i in ${DISTFILES}; do \
		${CP} ${_DISTDIR}$$i ${WRKDIR}; ${GUNZIP_CMD} ${WRKDIR}/$$i; \
	done
	${CP} ${.CURDIR}/../../fonts/ko-x11fonts/files/Makefile ${WRKSRC}
	(cd ${WRKSRC}; ${MAKE} prepare)

pre-install:
	[ -d ${FONTDIR} ] || ${INSTALL_DATA_DIR} ${FONTDIR}

post-install:
	(cd ${FONTDIR}; mkfontdir)

.include "../../mk/bsd.pkg.mk"
