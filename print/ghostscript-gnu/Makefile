# $NetBSD: Makefile,v 1.14 2006/07/27 18:48:03 jlam Exp $

DISTNAME=	ghostscript-${GS_VERS}
PKGNAME=	ghostscript-gnu-${GS_VERS}
PKGREVISION=	4
GS_VERS=	8.15
CATEGORIES=	print
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:=ghostscript/} \
		ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/gnu/gs${GS_VERS:S/.//}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GNU Postscript interpreter with all drivers
HOMEPAGE=	http://www.cs.wisc.edu/~ghost/index.html

CONFLICTS+=	ghostscript{,-nox11}-[0-9]*
CONFLICTS+=	ghostscript-afpl-[0-9]*
CONFLICTS+=	ghostscript-esp{,-nox11}-[0-9]*
CONFLICTS+=	ghostscript-gnu{,-nox11,-x11}-[0-9]*

DEPENDS+=	ghostscript-fonts>=6.0:../../fonts/ghostscript-fonts

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-ijs

DIST_SUBDIR=		ghostscript
GS_SRCS=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		${GS_SRCS}
EXTRACT_ONLY=		${GS_SRCS}

# Adobe's JPEG implementation in their PDF/PS documents is non-standard,
# so we can't use an already installed libjpeg.so.
#
JPEG_SRCS=		jpegsrc.v6b.tar.gz
JPEG_WRKSRC=		${WRKDIR}/jpeg-6b
SITES.${JPEG_SRCS}=	ftp://ftp.uu.net/graphics/jpeg/
DISTFILES+=		${JPEG_SRCS}
EXTRACT_ONLY+=		${JPEG_SRCS}

DISTINFO_FILE=		${.CURDIR}/../../print/ghostscript-gnu/distinfo
FILESDIR=		${.CURDIR}/../../print/ghostscript-gnu/files
PATCHDIR=		${.CURDIR}/../../print/ghostscript-gnu/patches
PLIST_SRC=		${.CURDIR}/../../print/ghostscript-gnu/PLIST

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Interix"
MAKE_FLAGS+=		XLIBS="Xt SM ICE Xext X11"
.endif

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=		3.0
.endif

.if defined(PAPERSIZE) && (${PAPERSIZE} == "A4" || ${PAPERSIZE} == "a4")
CFLAGS+=		-DA4
.endif
CFLAGS+=		-DHAVE_MKSTEMP=1

MAKE_FLAGS+=		XCFLAGS=${CFLAGS:M*:Q}
MAKE_FLAGS+=		XLDFLAGS=${LDFLAGS:M*:Q}

REPLACE_PERL=		lib/fixmswrd.pl
USE_TOOLS+=		perl:run

GS_RESOURCEDIR=		${PREFIX}/share/ghostscript/Resource
GSDATADIR=		${PREFIX}/share/ghostscript/${GS_VERS}
DOCDIR=			${PREFIX}/share/doc/ghostscript
HTMLDIR=		${PREFIX}/share/doc/html/ghostscript
LIBDIR=			${GSDATADIR}/lib

PLIST_SUBST+=		GS_VERS=${GS_VERS:Q}

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mmipspro*)
CFLAGS+=		-c99
.endif

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MKDIR} ${WRKSRC}/obj
	${RM} -f ${WRKSRC}/jpeg
	${LN} -s ${JPEG_WRKSRC} ${WRKSRC}/jpeg
	cd ${WRKSRC}/lib; for f in gs_res.ps; do				\
		${SED}  -e "s|/Resource/|${GS_RESOURCEDIR}/|g"		\
			$${f} > $${f}.fixed;				\
		${MV} -f $${f}.fixed $${f};				\
	done

# Reinstall the gs binary so that it's properly stripped.
post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/gs ${PREFIX}/bin/gs

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
