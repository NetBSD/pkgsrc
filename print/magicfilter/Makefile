# $NetBSD: Makefile,v 1.1 1998/06/23 21:35:55 tron Exp $

DISTNAME=	magicfilter-1.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/printing

MAINTAINER=	tron@netbsd.org

DEPENDS+=	a2ps-${PAPERSIZE}-4.9.9:../../print/a2ps \
		ghostscript-5.10:../../print/ghostscript5 \
		netpbm-94.3.1:../../graphics/netpbm \
		teTeX-0.4p8:../../print/teTeX

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_SRC=	${WRKDIR}/PLIST

post-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@(cd ${WRKSRC}/filters; \
	for FILTER in *-filter; do \
	    ${ECHO} ${INSTALL_SCRIPT} $$FILTER ${PREFIX}/libexec; \
	    ${INSTALL_SCRIPT} $$FILTER ${PREFIX}/libexec; \
	    ${ECHO} libexec/$$FILTER >>${PLIST_SRC}; \
	done)

.include "../../mk/bsd.pkg.mk"
