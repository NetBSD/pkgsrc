# $NetBSD: Makefile,v 1.24 2007/04/13 15:42:07 gdt Exp $

DISTNAME=	espgs-${GS_VERS}-source
PKGNAME=	ghostscript-esp-${GS_VERS}
PKGREVISION=	5
BASEGS_VERS=	8.15
GS_VERS=	${BASEGS_VERS}.1
CATEGORIES=	print
ESP_SITES=	http://ftp.easysw.com/pub/ghostscript/ \
		ftp://ftp.easysw.com/pub/ghostscript/ \
		ftp://ftp2.easysw.com/pub/ghostscript/ \
		ftp://ftp3.easysw.com/pub/ghostscript/ \
		http://ftp.funet.fi/pub/mirrors/ftp.easysw.com/pub/ghostscript/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.easysw.com/pub/ghostscript/ \
		ftp://ftp.rz.tu-bs.de/pub/mirror/ftp.easysw.com/ftp/pub/ghostscript/ \
		http://ftp.rz.tu-bs.de/pub/mirror/ftp.easysw.com/ftp/pub/ghostscript/
MASTER_SITES=	${ESP_SITES:=${GS_VERS}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jlam@pkgsrc.org
COMMENT=	ESP/CUPS Postscript interpreter
HOMEPAGE=	http://www.cups.org/espgs/

CONFLICTS+=	ghostscript{,-nox11}-[0-9]*
CONFLICTS+=	ghostscript-afpl-[0-9]*
CONFLICTS+=	ghostscript-esp{,-nox11}-[0-9]*
CONFLICTS+=	ghostscript-gnu{,-nox11,-x11}-[0-9]*

DEPENDS+=	ghostscript-fonts>=6.0:../../fonts/ghostscript-fonts

# uses include file apparently before it is put in place
MAKE_JOBS_SAFE=	no

WRKSRC=			${WRKDIR}/${DISTNAME:S/-source//}
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ijs
CONFIGURE_ARGS+=	--without-omni
CONFIGURE_ARGS+=	--with-drivers=ALL
CONFIGURE_ARGS+=	${CONFIGURE_ARGS_ICONV.${USE_BUILTIN.iconv}}

# Force the configure script to select the correct iconv library.  The
# "maybe" setting looks for iconv in libc first, then falls back to
# checking -liconv, while "gnu" looks directly in -liconv.
#
CONFIGURE_ARGS_ICONV.yes=	--with-libiconv=maybe
CONFIGURE_ARGS_ICONV.no=	--with-libiconv=gnu

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

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=	3.0
.endif

.if defined(PAPERSIZE) && (${PAPERSIZE} == "A4" || ${PAPERSIZE} == "a4")
CFLAGS+=		-DA4
.endif
CFLAGS+=		-DHAVE_MKSTEMP=1

REPLACE_PERL=		lib/fixmswrd.pl

DOCDIR=			${PREFIX}/share/doc/ghostscript

PLIST_SUBST+=		GS_VERS=${BASEGS_VERS:Q}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../print/gimp-print-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MKDIR} ${WRKSRC}/obj
	${RM} -f ${WRKSRC}/jpeg
	${LN} -s ${JPEG_WRKSRC} ${WRKSRC}/jpeg

SUBST_CLASSES+=		ps2epsi-sh
SUBST_MESSAGE.ps2epsi-sh=   Fixing ps2epsi shell.
SUBST_FILES.ps2epsi-sh=     lib/ps2epsi
SUBST_SED.ps2epsi-sh=       -e 's|/bin/sh|${SH}|'
SUBST_STAGE.ps2epsi-sh=     post-patch

.include "../../mk/bsd.pkg.mk"
