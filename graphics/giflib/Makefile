# $NetBSD: Makefile,v 1.38 2004/10/03 00:14:51 tv Exp $
#

DISTNAME=		giflib-4.1.0
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		ftp://prtr-13.ucsc.edu/pub/libungif/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://prtr-13.ucsc.edu/~badger/software/libungif/index.shtml
COMMENT=		Tools and library routines for working with GIF images

CONFLICTS=		libungif-[0-9]*

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS=		--without-x
USE_BUILDLINK3=		# defined
USE_LIBTOOL=		# defined

DOCDIR=			${PREFIX}/share/doc/giflib
HTMLDIR=		${PREFIX}/share/doc/html/giflib

post-patch:
	${RM} ${WRKSRC}/doc/gif2x11.html

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} COPYING PATENT_PROBLEMS ${DOCDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html *.txt *.png ${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
