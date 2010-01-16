# $NetBSD: Makefile,v 1.2 2010/01/16 03:35:41 minskim Exp $

DISTNAME=	texlive-20091011-source
PKGNAME=	ps2pkm-1.5
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Tool to convert PostSCript fonts into TeX PK fonts

CONFLICTS+=	teTeX-bin<=3.0nb34

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/ps2pkm

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/ps2pkm

CONFIGURE_ARGS+=	--with-system-kpathsea \
		--with-kpathsea-includes=${BUILDLINK_PREFIX.kpathsea}/include \
		--with-kpathsea-libdir=${BUILDLINK_PREFIX.kpathsea}/lib

.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
