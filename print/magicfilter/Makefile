# $NetBSD: Makefile,v 1.23 2000/04/10 00:06:28 jlam Exp $

DISTNAME=	magicfilter-1.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/printing/}

MAINTAINER=	packages@netbsd.org

DEPENDS+=	a2ps-*:../../print/a2ps
DEPENDS+=	ghostscript-[0-9]*:../../print/ghostscript5
DEPENDS+=	netpbm-*:../../graphics/netpbm
DEPENDS+=	teTeX-bin-*:../../print/teTeX-bin
DEPENDS+=	papersize-*:../../print/papersize

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	GHOSTSCRIPT=${LOCALBASE}/bin/gstty

PLIST_SRC=	${WRKDIR}/PLIST

FILTER_DIR=	libexec/magicfilter

.include "../../mk/bsd.prefs.mk"

PAPERSIZE?=	A4

post-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@${MKDIR} ${PREFIX}/${FILTER_DIR}
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
