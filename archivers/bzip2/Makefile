# $NetBSD: Makefile,v 1.29 2004/01/06 08:17:55 jlam Exp $
#

DISTNAME=	bzip2-1.0.2
CATEGORIES=	archivers
MASTER_SITES=	ftp://sources.redhat.com/pub/bzip2/v102/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sources.redhat.com/bzip2/
COMMENT=	Block-sorting file compressor

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
MAKE_ENV+=		REALCC="${BUILDLINK_CC}"

.include "../../mk/bsd.prefs.mk"

.if !empty(CC_VERSION:Mgcc*)
BZIP_CFLAGS=           -Wall -Winline -fomit-frame-pointer -fno-strength-reduce
.endif

MAKE_ENV+=		BZIP_CFLAGS="${BZIP_CFLAGS}"
INSTALLATION_DIRS=	bin include lib man/man1

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} ${WRKSRC}/libbz2.la ${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/bzip2 ${PREFIX}/bin
	${LN} -f ${PREFIX}/bin/bzip2 ${PREFIX}/bin/bunzip2
	${LN} -f ${PREFIX}/bin/bzip2 ${PREFIX}/bin/bzcat
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/bzip2recover ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bzip2.1 ${PREFIX}/man/man1
	${RM} -f ${PREFIX}/man/man1/bunzip2.1 ${PREFIX}/man/man1/bzcat.1 ${PREFIX}/man/man1/bzip2recover.1
	${LN} -s ${PREFIX}/man/man1/bzip2.1 ${PREFIX}/man/man1/bunzip2.1
	${LN} -s ${PREFIX}/man/man1/bzip2.1 ${PREFIX}/man/man1/bzcat.1
	${LN} -s ${PREFIX}/man/man1/bzip2.1 ${PREFIX}/man/man1/bzip2recover.1
	${INSTALL_DATA} ${WRKSRC}/bzlib.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
