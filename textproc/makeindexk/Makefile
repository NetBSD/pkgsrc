# $NetBSD: Makefile,v 1.2 2009/06/09 21:31:03 minskim Exp $

DISTNAME=	texlive-20080816-source
PKGNAME=	makeindexk-2.15
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.lzma

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	General purpose hierarchical index generator

CONFLICTS+=	teTeX-bin<=3.0nb32

EXTRACT_ELEMENTS=	${DISTNAME}/texk/makeindexk \
			${DISTNAME}/texk/make \
			${DISTNAME}/texk/install.sh \
			${DISTNAME}/texk/mkinstalldirs

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/makeindexk

MAKE_ENV+=	KPATHSEA_PREFIX=${BUILDLINK_PREFIX.kpathsea}
MAKE_FLAGS+=	LIBTOOL=${LIBTOOL:Q} \
		kpathsea_parent=${BUILDLINK_PREFIX.kpathsea}/include \
		kpathsea_srcdir=${BUILDLINK_PREFIX.kpathsea}/include/kpathsea \
		kpathsea=${BUILDLINK_PREFIX.kpathsea}/lib/libkpathsea.la

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			infodir=${DESTDIR}${PREFIX}/${PKGINFODIR} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
