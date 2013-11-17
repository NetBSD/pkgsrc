# $NetBSD: Makefile,v 1.5 2013/11/17 16:46:36 minskim Exp $

DISTNAME=	texlive-20130530-source
PKGNAME=	ptexenc-1.3.1
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2013/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Library for Japanese pTeX and its tools
LICENSE=	modified-bsd

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/ptexenc

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/ptexenc

CONFIGURE_ARGS+=	--with-system-kpathsea \
		--with-kpathsea-includes=${BUILDLINK_PREFIX.kpathsea}/include \
		--with-kpathsea-libdir=${BUILDLINK_PREFIX.kpathsea}/lib

.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
