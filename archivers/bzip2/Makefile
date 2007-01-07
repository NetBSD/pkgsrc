# $NetBSD: Makefile,v 1.42.8.1 2007/01/07 03:52:44 salo Exp $
#

DISTNAME=	bzip2-1.0.4
CATEGORIES=	archivers
MASTER_SITES=	http://www.bzip.org/1.0.4/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bzip.org/
COMMENT=	Block-sorting file compressor

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
MAKE_ENV+=		REALCC=${CC:Q}

.include "../../mk/compiler.mk"

CFLAGS+=		${CPPFLAGS}
.if !empty(CC_VERSION:Mgcc*)
CFLAGS+=		-Wall -Winline -fomit-frame-pointer -fno-strength-reduce
.endif

INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libbz2.la ${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/bzip2 ${PREFIX}/bin
	${LN} -f ${PREFIX}/bin/bzip2 ${PREFIX}/bin/bunzip2
	${LN} -f ${PREFIX}/bin/bzip2 ${PREFIX}/bin/bzcat
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/bzip2recover ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bzip2.1 ${PREFIX}/${PKGMANDIR}/man1
	${RM} -f ${PREFIX}/${PKGMANDIR}/man1/bunzip2.1 ${PREFIX}/${PKGMANDIR}/man1/bzcat.1 ${PREFIX}/${PKGMANDIR}/man1/bzip2recover.1
	${LN} -s ${PREFIX}/${PKGMANDIR}/man1/bzip2.1 ${PREFIX}/${PKGMANDIR}/man1/bunzip2.1
	${LN} -s ${PREFIX}/${PKGMANDIR}/man1/bzip2.1 ${PREFIX}/${PKGMANDIR}/man1/bzcat.1
	${LN} -s ${PREFIX}/${PKGMANDIR}/man1/bzip2.1 ${PREFIX}/${PKGMANDIR}/man1/bzip2recover.1
	${INSTALL_DATA} ${WRKSRC}/bzlib.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
