# $NetBSD: Makefile,v 1.20.2.1 2002/06/06 06:54:40 jlam Exp $
#

DISTNAME=	libungif-4.1.0b1
PKGNAME=	libungif-4.1.0.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://prtr-13.ucsc.edu/pub/libungif/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://prtr-13.ucsc.edu/~badger/software/libungif/index.shtml
COMMENT=	Tools and library routines for working with GIF images

CONFLICTS=	giflib-[0-9]*

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS=		--without-x

USE_BUILDLINK2_ONLY=	# defined

DOCDIR=			${PREFIX}/share/doc/libungif
HTMLDIR=		${PREFIX}/share/doc/html/libungif

post-patch:
	${RM} ${WRKSRC}/doc/gif2x11.html

post-install:
	cd ${PREFIX}; \
	for f in libungif.a libungif.so libungif.so.5 libungif.so.5.0; do \
		g=`echo $$f | ${SED} "s,libungif,libgif,"`; \
		${LN} -sf $$f ${PREFIX}/lib/$$g; \
	done
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} COPYING UNCOMPRESSED_GIF ${DOCDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html *.txt *.png ${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
