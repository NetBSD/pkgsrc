# $NetBSD: Makefile,v 1.44 2005/11/11 18:50:25 tonio Exp $

DISTNAME=	magicfilter-1.2
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/printing/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Customizable, extensible automatic printer filter

# Any version will do:
#
DEPENDS+=	a2ps-[0-9]*:../../print/a2ps
DEPENDS+=	netpbm-[0-9]*:../../graphics/netpbm
DEPENDS+=	papersize-[0-9]*:../../print/papersize

USE_TOOLS+=	gmake gzip
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	GHOSTSCRIPT=${LOCALBASE}/bin/gs
CONFIGURE_ENV+= GZIP=${TOOLS_GZIP_CMD:Q}
TEX_ACCEPTED=	teTeX1 teTeX2 teTeX3

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

.include "../../mk/ghostscript.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
