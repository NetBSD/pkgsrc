# $NetBSD: Makefile,v 1.25 1998/11/04 21:42:11 mycroft Exp $
#

DISTNAME=	ghostscript-5.50
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.cs.wisc.edu/ghost/aladdin/gs550/ \
		ftp://ftp.cs.wisc.edu/ghost/aladdin/fonts/ \
		ftp://bonk.ethz.ch/gs-driver-distrib/ \
		http://www.ozemail.com.au/~geoffk/pdfencrypt/
DISTFILES=	${GS_SOURCES} ${GS_FONTS_STD} ${GS_FONTS_OTHER} \
		${HP850_DRV} ${PDF_SEC}

MAINTAINER=	explorer@netbsd.org
HOMEPAGE=	http://www.cs.wisc.edu/~ghost/index.html

BUILD_DEPENDS=	${BUILD_ROOT}/graphics/jpeg/${WRKDIR:T}/jpeg-6b:../../graphics/jpeg:extract \
		libpng-1.0.2:../../graphics/png \
		unzip:../../archivers/unzip

CONFLICTS=	ghostscript-5.10

EXTRACT_ONLY=	${GS_SOURCES}
WRKSRC=		${WRKDIR}/gs5.50
MAKEFILE=	unix-gcc.mak
ALL_TARGET=	std
MAKE_ENV+=	MAKEOBJDIR=.
MAKE_FLAGS=	prefix=${PREFIX} CFLAGS="${CFLAGS}"

GS_SOURCES=	ghostscript-5.50.tar.gz
GS_SOURCES+=	ghostscript-5.50gnu.tar.gz
#  Note: the following two are special files.  In the 5.50 directory
#  on the FTP site, there are symlinks:
#        ghostscript-fonts-other-5.50.tar.gz ->
#               ../fonts/ghostscript-fonts-other-4.40.tar.gz
#  To avoid unnecessarily downloading distfiles, do not change these
#  when upgrading the port unless the symlinks/files really change.
GS_FONTS_STD=	ghostscript-fonts-std-5.10a.tar.gz
GS_FONTS_OTHER=	ghostscript-fonts-other-5.10.tar.gz

# Additional driver HP 850, see http://bonk.ethz.ch/hp850/hp850.html
HP850_DRV=	hp850.zip

# PostScript source to decode encrypted PDF files
PDF_SEC=	pdf_sec.ps

.include "../../mk/bsd.prefs.mk"

.ifdef WRKOBJDIR
BUILD_ROOT=	${WRKOBJDIR}
.else
BUILD_ROOT=	${PKGSRCDIR}
.endif

.if defined(PAPERSIZE) && (${PAPERSIZE} == "A4" || ${PAPERSIZE} == "a4")
PAPERSIZE_DEF=	-DA4
.endif

.if defined(BATCH)
SCRIPT_SUFFIX=	.batch
.endif

post-extract:
	${LN} -s ${BUILD_ROOT}/graphics/jpeg/${WRKDIR:T}/jpeg-6b ${WRKSRC}/jpeg
	cd ${WRKSRC} && unzip -La ${DISTDIR}/${HP850_DRV}
	${CP} ${DISTDIR}/${PDF_SEC} ${WRKSRC}

do-configure:
	@${SETENV} WRKSRC=${WRKSRC} \
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

.include "../../mk/bsd.pkg.mk"
