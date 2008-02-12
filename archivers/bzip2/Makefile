# $NetBSD: Makefile,v 1.46 2008/02/12 11:25:35 tnn Exp $
#

DISTNAME=	bzip2-1.0.4
CATEGORIES=	archivers
MASTER_SITES=	http://www.bzip.org/1.0.4/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.bzip.org/
COMMENT=	Block-sorting file compressor

DISTFILES=	# empty
EXTRACT_ONLY=	# empty

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no
NO_CHECKSUM=		yes
USE_LIBTOOL=		yes

.include "../../mk/compiler.mk"

CFLAGS+=		${CPPFLAGS}
.if !empty(CC_VERSION:Mgcc*)
CFLAGS+=		-Wall -Winline -fomit-frame-pointer
.endif

INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1

do-extract:
	${CP} -r ${FILESDIR} ${WRKSRC}

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libbz2.la ${DESTDIR}${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/bzip2 ${DESTDIR}${PREFIX}/bin
	${LN} -f ${DESTDIR}${PREFIX}/bin/bzip2 ${DESTDIR}${PREFIX}/bin/bunzip2
	${LN} -f ${DESTDIR}${PREFIX}/bin/bzip2 ${DESTDIR}${PREFIX}/bin/bzcat
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/bzip2recover ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bzip2.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 && rm -f bunzip2.1 bzcat.1 bzip2recover.1
	${LN} -s bzip2.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/bunzip2.1
	${LN} -s bzip2.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/bzcat.1
	${LN} -s bzip2.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/bzip2recover.1
	${INSTALL_DATA} ${WRKSRC}/bzlib.h ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
