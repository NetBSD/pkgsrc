# $NetBSD: Makefile,v 1.4 2013/12/06 02:36:54 minskim Exp $

DISTNAME=	texlive-20130530-source
PKGNAME=	mendexk-2.6f
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2013/
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
		--with-ptexenc-includes=${BUILDLINK_PREFIX.ptexenc}/include \
		--with-ptexenc-libdir=${BUILDLINK_PREFIX.ptexenc}/lib

.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/ptexenc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
