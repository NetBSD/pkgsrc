# $NetBSD: Makefile,v 1.3 2012/10/25 06:56:07 asau Exp $

DISTNAME=	texlive-20110705-source
PKGNAME=	mendexk-2.6f
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Replacement for makeindex with many enhancements
LICENSE=	modified-bsd

CONFLICTS+=	ja-ptex-bin-[0-9]*

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/mendexk

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/mendexk

CONFIGURE_ARGS+=	--with-system-kpathsea \
		--with-kpathsea-includes=${BUILDLINK_PREFIX.kpathsea}/include \
		--with-kpathsea-libdir=${BUILDLINK_PREFIX.kpathsea}/lib \
		--with-system-ptexenc \
		--with-kpathsea-includes=${BUILDLINK_PREFIX.ptexenc}/include \
		--with-kpathsea-libdir=${BUILDLINK_PREFIX.ptexenc}/lib

.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/ptexenc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
