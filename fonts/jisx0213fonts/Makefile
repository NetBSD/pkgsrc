# $NetBSD: Makefile,v 1.1.1.1 2000/04/09 15:18:33 itojun Exp $
#

DISTNAME=	jisx0213fonts-0.0
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.m17n.org/pub/character/fonts/imamura/jisx0213/
DISTFILES=	${BDF:C/bdf$/bdf.gz/}

MAINTAINER=	itojun@itojun.org
HOMEPAGE=	ftp://ftp.m17n.org/pub/character/fonts/imamura/jisx0213/

USE_X11BASE=	yes

BDF=	K14-1.bdf K14-2.bdf jiskan16-2000-1.bdf jiskan16-2000-2.bdf
PCF=	${BDF:C/bdf$/pcf/}
PCFGZ=	${BDF:C/bdf$/pcf.gz/}
FONTDIR=${PREFIX}/lib/X11/fonts/local

do-extract:
	${MKDIR} ${WRKSRC}
	for i in ${BDF}; do \
		${CP} ${DISTDIR}/$$i.gz ${WRKSRC}; \
		${GUNZIP_CMD} ${WRKSRC}/$$i.gz; \
	done

do-build:
	(cd ${WRKSRC}; for i in ${BDF}; do \
		bdftopcf -o `echo $$i | ${SED} -e 's/bdf$$/pcf/'` $$i; \
		${GZIP_CMD} `echo $$i | ${SED} -e 's/bdf$$/pcf/'`; \
	done)

do-install:
	${MKDIR} ${FONTDIR}
	for i in ${PCFGZ}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${FONTDIR}; \
	done
	(cd ${FONTDIR}; mkfontdir)

.include "../../mk/bsd.pkg.mk"
