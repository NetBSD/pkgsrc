# $NetBSD: Makefile,v 1.3 1998/07/05 10:09:58 tron Exp $

DISTNAME=	magicfilter-1.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/printing

MAINTAINER=	tron@netbsd.org

DEPENDS+=	a2ps-${PAPERSIZE}-4.10.3:../../print/a2ps \
		ghostscript-5.10:../../print/ghostscript5 \
		netpbm-19940301:../../graphics/netpbm \
		teTeX-0.4p8:../../print/teTeX

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_SRC=	${WRKDIR}/PLIST

FILTER_DIR=	libexec/magicfilter

post-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@${MKDIR} ${PREFIX}/${FILTER_DIR}
	@(cd ${WRKSRC}/filters; \
	for FILTER in *-filter; do \
	    ${ECHO} ${INSTALL_SCRIPT} $$FILTER ${PREFIX}/${FILTER_DIR}; \
	    ${INSTALL_SCRIPT} $$FILTER ${PREFIX}/${FILTER_DIR}; \
	    ${ECHO} ${FILTER_DIR}/$$FILTER >>${PLIST_SRC}; \
	done)
	${ECHO} "@dirrm ${FILTER_DIR}" >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
