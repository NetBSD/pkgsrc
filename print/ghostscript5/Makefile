# $NetBSD: Makefile,v 1.23 1998/08/20 15:17:23 tsarna Exp $
# FreeBSD Id: Makefile,v 1.14 1997/10/13 11:22:43 asami Exp
#

DISTNAME=	ghostscript-5.10
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.cs.wisc.edu/ghost/aladdin/gs510/ \
		ftp://ftp.cs.wisc.edu/ghost/aladdin/fonts/ \
		ftp://bonk.ethz.ch/gs-driver-distrib/ \
		http://www.ozemail.com.au/~geoffk/pdfencrypt/
DISTFILES=	${GS_SOURCES} ${GS_FONTS_STD} ${GS_FONTS_OTHER} \
		${HP850_DRV} ${PDF_SEC}

MAINTAINER=	explorer@netbsd.org
HOMEPAGE=	http://www.cs.wisc.edu/~ghost/index.html

BUILD_DEPENDS=	../../graphics/jpeg/${WRKDIR:T}/jpeg-6b:../../graphics/jpeg:extract \
		../../graphics/png/${WRKDIR:T}/libpng-1.0.2:../../graphics/png:extract \
		unzip:../../archivers/unzip

MAKE_ENV=	PORTSDIR=${.CURDIR}/../..
EXTRACT_ONLY=	${GS_SOURCES}
WRKSRC=		${WRKDIR}/gs5.10
MAKEFILE=	unix-gcc.mak
MAKE_FLAGS=	prefix=${PREFIX} zlibc_=-lz CFLAGS="${CFLAGS}" JSRCDIR=jpeg-6b

GS_SOURCES=	ghostscript-5.10.tar.gz
GS_SOURCES+=	ghostscript-5.10gnu.tar.gz
#  Note: the following two are special files.  In the 5.10 directory
#  on the FTP site, there are symlinks:
#        ghostscript-fonts-other-5.10.tar.gz ->
#               ../fonts/ghostscript-fonts-other-4.40.tar.gz
#  To avoid unnecessarily downloading distfiles, do not change these
#  when upgrading the port unless the symlinks/files really change.
GS_FONTS_STD=	ghostscript-fonts-std-4.0.tar.gz
GS_FONTS_OTHER=	ghostscript-fonts-other-4.40.tar.gz

# Additional driver HP 850, see http://bonk.ethz.ch/hp850/hp850.html
HP850_DRV=	hp850.zip

# PostScript source to decode encrypted PDF files
PDF_SEC=	pdf_sec.ps

.include "../../mk/bsd.prefs.mk"

.if defined(PAPERSIZE) && (${PAPERSIZE} == "A4" || ${PAPERSIZE} == "a4")
PAPERSIZE_DEF=	-DA4
.endif

.if defined(BATCH)
SCRIPT_SUFFIX=	.batch
.endif

post-extract:
	${TOUCH} ${WRKSRC}/adler32.c
	${TOUCH} ${WRKSRC}/deflate.c
	${TOUCH} ${WRKSRC}/trees.c
	${TOUCH} ${WRKSRC}/adler32.o
	${TOUCH} ${WRKSRC}/deflate.o
	${TOUCH} ${WRKSRC}/trees.o
	${LN} -s ${PKGSRCDIR}/graphics/jpeg/${WRKDIR:T}/jpeg-6b ${WRKSRC}/jpeg-6b
	${LN} -s ${PKGSRCDIR}/graphics/png/${WRKDIR:T}/libpng-1.0.2 ${WRKSRC}/libpng
	cd ${WRKSRC} && unzip -La ${DISTDIR}/${HP850_DRV}
	${CP} ${DISTDIR}/${PDF_SEC} ${WRKSRC}

do-configure:
	@${SETENV} PORTSDIR=${.CURDIR}/../.. WRKSRC=${WRKSRC} \
		${SH} ${SCRIPTDIR}/configure${SCRIPT_SUFFIX}

do-build:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${PAPERSIZE_DEF} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}

pre-install:
	@${MKDIR} ${PREFIX}/share/ghostscript ${PREFIX}/bin ${PREFIX}/man/man1
	(cd ${PREFIX}/share/ghostscript ; \
			tar -xzf ${DISTDIR}/${GS_FONTS_STD})
	(cd ${PREFIX}/share/ghostscript/fonts ; \
			tar -xzf ${DISTDIR}/${GS_FONTS_OTHER})

post-install:
	strip ${PREFIX}/bin/gs

pre-clean:
	@cd ../../graphics/jpeg && ${MAKE} clean
	@cd ../../graphics/png && ${MAKE} clean

.include "../../mk/bsd.pkg.mk"
