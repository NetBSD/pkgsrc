# $NetBSD: Makefile,v 1.6 1998/10/12 22:21:49 tron Exp $

DISTNAME=	magicfilter-1.2
PKGNAME=	magicfilter-${PAPERSIZE}-1.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/printing

MAINTAINER=	tron@netbsd.org

DEPENDS+=	a2ps-${PAPERSIZE}-4.10.3:../../print/a2ps \
		ghostscript-5.10:../../print/ghostscript5 \
		netpbm-19940301:../../graphics/netpbm \
		teTeX-0.4p8:../../print/teTeX

CONFLICTS=	magicfilter-1.2

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_SRC=	${WRKDIR}/PLIST

PAPERSIZE?=	A4
FILTER_DIR=	libexec/magicfilter

post-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@${MKDIR} ${PREFIX}/${FILTER_DIR}
	@(cd ${WRKSRC}/filters; \
	  for FILTER in *-filter; do \
	    TARGET=${PREFIX}/${FILTER_DIR}/$$FILTER; \
	    ${ECHO} "Installing $$FILTER as $$TARGET"; \
	    ${SED} 's/-sOutputFile=-/-sOutputFile=- ${GS_OPTS}/' \
		<$$FILTER >${PREFIX}/${FILTER_DIR}/$$FILTER; \
	    chown ${BINOWN}:${BINGRP} $$TARGET; \
	    chmod ${BINMODE} $$TARGET; \
	    ${ECHO} ${FILTER_DIR}/$$FILTER >>${PLIST_SRC}; \
	  done)
	@${ECHO} "@dirrm ${FILTER_DIR}" >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"

.if ${PAPERSIZE} == A4
GS_OPTS=	-sPAPERSIZE=a4
.else
GS_OPTS=	-sPAPERSIZE=letter
.endif
