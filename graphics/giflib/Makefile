# $NetBSD: Makefile,v 1.34 2002/11/15 00:00:41 jlam Exp $
#

DISTNAME=		giflib-4.1.0
CATEGORIES=		graphics
MASTER_SITES=		ftp://prtr-13.ucsc.edu/pub/libungif/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://prtr-13.ucsc.edu/~badger/software/libungif/index.shtml
COMMENT=		Tools and library routines for working with GIF images

CONFLICTS=		libungif-[0-9]*

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS=		--without-x

USE_BUILDLINK2=		# defined

DOCDIR=			${PREFIX}/share/doc/giflib
HTMLDIR=		${PREFIX}/share/doc/html/giflib

.include "../../mk/bsd.prefs.mk"

post-patch:
	${RM} ${WRKSRC}/doc/gif2x11.html

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} COPYING PATENT_PROBLEMS ${DOCDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html *.txt *.png ${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
