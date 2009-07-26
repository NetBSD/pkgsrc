# $NetBSD: Makefile,v 1.1.1.1 2009/07/26 23:41:25 minskim Exp $

DISTNAME=	texlive-20080816-source
PKGNAME=	gsftopkk-1.19.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.lzma

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://math.berkeley.edu/~vojta/gsftopk.html
COMMENT=	Tool to convert bitmaps to .pk format

CONFLICTS+=	teTeX-bin<=3.0nb34
DEPENDS+=	ghostscript>=2.5.2:../../print/ghostscript

EXTRACT_ELEMENTS=	${DISTNAME}/texk/gsftopk \
			${DISTNAME}/texk/make \
			${DISTNAME}/texk/install.sh \
			${DISTNAME}/texk/mkinstalldirs

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/gsftopk

FIND_PREFIX:=	GHOSTSCRIPT_PREFIX=ghostscript
.include "../../mk/find-prefix.mk"

MAKE_ENV+=	XCFLAGS="-DGS_PATH='\"${GHOSTSCRIPT_PREFIX}/bin/gs\"'"
MAKE_ENV+=	KPATHSEA_PREFIX=${BUILDLINK_PREFIX.kpathsea}
MAKE_FLAGS+=	LIBTOOL=${LIBTOOL:Q} \
		kpathsea_parent=${BUILDLINK_PREFIX.kpathsea}/include \
		kpathsea_srcdir=${BUILDLINK_PREFIX.kpathsea}/include/kpathsea \
		kpathsea=${BUILDLINK_PREFIX.kpathsea}/lib/libkpathsea.la

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			infodir=${DESTDIR}${PREFIX}/${PKGINFODIR} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/kpathsea/texmf.mk"
.include "../../mk/bsd.pkg.mk"
