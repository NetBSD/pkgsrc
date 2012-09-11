# $NetBSD: Makefile,v 1.52 2012/09/11 19:46:53 asau Exp $
#

DISTNAME=	bzip2-1.0.6
CATEGORIES=	archivers
MASTER_SITES=	http://www.bzip.org/1.0.6/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.bzip.org/
COMMENT=	Block-sorting file compressor

DISTFILES=	# empty

PKG_INSTALLATION_TYPES=	overwrite pkgviews
REPLACE_SH=	bzdiff bzgrep bzmore

MAKE_JOBS_SAFE=		no
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
	${INSTALL_SCRIPT} ${WRKSRC}/bzmore ${DESTDIR}${PREFIX}/bin/bzmore
	${LN} -s bzmore ${DESTDIR}${PREFIX}/bin/bzless
	${INSTALL_MAN} ${WRKSRC}/bzmore.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${LN} -s bzmore.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/bzless.1
	${INSTALL_SCRIPT} ${WRKSRC}/bzdiff ${DESTDIR}${PREFIX}/bin/bzdiff
	${LN} -s bzdiff ${DESTDIR}${PREFIX}/bin/bzcmp
	${INSTALL_MAN} ${WRKSRC}/bzdiff.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${LN} -s bzdiff.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/bzcmp.1
	${INSTALL_SCRIPT} ${WRKSRC}/bzgrep ${DESTDIR}${PREFIX}/bin/bzgrep
	${LN} -s bzgrep ${DESTDIR}${PREFIX}/bin/bzegrep
	${LN} -s bzgrep ${DESTDIR}${PREFIX}/bin/bzfgrep
	${INSTALL_MAN} ${WRKSRC}/bzgrep.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${LN} -s bzgrep.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/bzegrep.1
	${LN} -s bzgrep.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/bzfgrep.1

.include "../../mk/bsd.pkg.mk"
