# $NetBSD: Makefile,v 1.30 2001/09/27 23:18:36 jlam Exp $

DISTNAME=	magicfilter-1.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/printing/}

MAINTAINER=	packages@netbsd.org
COMMENT=	customizable, extensible automatic printer filter

DEPENDS+=	a2ps-[0-9]*:../../print/a2ps
DEPENDS+=	ghostscript{,-nox11}-[6-9]*:../../print/ghostscript
DEPENDS+=	netpbm-[0-9]*:../../graphics/netpbm
DEPENDS+=	teTeX-bin-[0-9]*:../../print/teTeX-bin
DEPENDS+=	papersize-[0-9]*:../../print/papersize

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	GHOSTSCRIPT=${LOCALBASE}/bin/gs

PLIST_SRC=	${WRKDIR}/PLIST

FILTER_DIR=	libexec/magicfilter

.include "../../mk/bsd.prefs.mk"

PAPERSIZE?=	A4

post-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@${INSTALL_DATA_DIR} ${PREFIX}/${FILTER_DIR}
	@(cd ${WRKSRC}/filters;	\
	  paper=`${ECHO} ${PAPERSIZE} | ${TR} '[A-Z]' '[a-z]'`; \
	  for FILTER in *-filter; do \
	    TARGET=${PREFIX}/${FILTER_DIR}/$$FILTER; \
	    ${ECHO} "Installing $$FILTER as $$TARGET"; \
	    ${SED} 's/-sOutputFile=-/-sOutputFile=- -sPAPERSIZE='$$paper'/' \
		<$$FILTER >${PREFIX}/${FILTER_DIR}/$$FILTER; \
	    ${CHOWN} ${BINOWN}:${BINGRP} $$TARGET; \
	    ${CHMOD} ${BINMODE} $$TARGET; \
	    ${ECHO} ${FILTER_DIR}/$$FILTER >>${PLIST_SRC}; \
	  done)
	@${ECHO} "@dirrm ${FILTER_DIR}" >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
