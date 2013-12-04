# $NetBSD: Makefile,v 1.6 2013/12/04 03:35:27 minskim Exp $

DISTNAME=	texlive-20130530-source
PKGNAME=	ps2pkm-1.5
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2013/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Tool to convert PostSCript fonts into TeX PK fonts

CONFLICTS+=	teTeX-bin<=3.0nb34
DEPENDS+=	kpathsea>=6.0.1:../../print/kpathsea

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/ps2pkm

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/ps2pkm

CONFIGURE_ARGS+=	--with-system-kpathsea \
		--with-kpathsea-includes=${BUILDLINK_PREFIX.kpathsea}/include \
		--with-kpathsea-libdir=${BUILDLINK_PREFIX.kpathsea}/lib

.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
