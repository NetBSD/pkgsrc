# $NetBSD: Makefile,v 1.18.2.1 2002/05/11 02:08:47 jlam Exp $
#

DISTNAME=	bzip2-1.0.2
CATEGORIES=	archivers
MASTER_SITES=	ftp://sourceware.cygnus.com/pub/bzip2/v102/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://sourceware.cygnus.com/bzip2/
COMMENT=	Block-sorting file compressor

USE_BUILDLINK2_ONLY=	# defined
USE_LIBTOOL=		# defined
MAKE_ENV+=		REALCC="${BUILDLINK_CC}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bzip2 ${PREFIX}/bin
	${LN} -f ${PREFIX}/bin/bzip2 ${PREFIX}/bin/bunzip2
	${LN} -f ${PREFIX}/bin/bzip2 ${PREFIX}/bin/bzcat
	${INSTALL_PROGRAM} ${WRKSRC}/bzip2recover ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bzip2.1 ${PREFIX}/man/man1
	${RM} -f ${PREFIX}/man/man1/bunzip2.1 ${PREFIX}/man/man1/bzcat.1 ${PREFIX}/man/man1/bzip2recover.1
	${LN} -s ${PREFIX}/man/man1/bzip2.1 ${PREFIX}/man/man1/bunzip2.1
	${LN} -s ${PREFIX}/man/man1/bzip2.1 ${PREFIX}/man/man1/bzcat.1
	${LN} -s ${PREFIX}/man/man1/bzip2.1 ${PREFIX}/man/man1/bzip2recover.1
	${INSTALL_DATA} ${WRKSRC}/bzlib.h ${PREFIX}/include
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/libbz2.la ${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
