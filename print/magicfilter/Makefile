# $NetBSD: Makefile,v 1.10 1998/11/11 00:28:45 tron Exp $

DISTNAME=	magicfilter-1.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/printing

MAINTAINER=	tron@netbsd.org

DEPENDS+=	a2ps-4.10.3:../../print/a2ps			\
		ghostscript-5.50:../../print/ghostscript5	\
		netpbm-19940301:../../graphics/netpbm		\
		teTeX-0.4p8:../../print/teTeX			\
		papersize-1.0:../../print/papersize

CONFLICTS=	magicfilter-A4-1.2 magicfilter-Letter-1.2

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_SRC=	${WRKDIR}/PLIST

FILTER_DIR=	libexec/magicfilter

post-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@${MKDIR} ${PREFIX}/${FILTER_DIR}
	@(cd ${WRKSRC}/filters;	\
	  for FILTER in *-filter; do \
	    TARGET=${PREFIX}/${FILTER_DIR}/$$FILTER; \
	    ${ECHO} "Installing $$FILTER as $$TARGET"; \
	    ${SED} 's/-sOutputFile=-/-sOutputFile=- -sPAPERSIZE=${PSIZE}/' \
		<$$FILTER >${PREFIX}/${FILTER_DIR}/$$FILTER; \
	    chown ${BINOWN}:${BINGRP} $$TARGET; \
	    chmod ${BINMODE} $$TARGET; \
	    ${ECHO} ${FILTER_DIR}/$$FILTER >>${PLIST_SRC}; \
	  done)
	@${ECHO} "@dirrm ${FILTER_DIR}" >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"

PSIZE!=		echo ${PAPERSIZE} | tr '[A-Z]' '[a-z]'
