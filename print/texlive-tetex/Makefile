# $NetBSD: Makefile,v 1.14 2013/11/14 06:13:07 minskim Exp $

DISTNAME=	texlive-20110705-source
PKGNAME=	texlive-tetex-2011
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Scripts included in teTeX

CONFLICTS+=	teTeX-bin<=3.0nb22
DEPENDS+=	kpathsea-[0-9]*:../../print/kpathsea
DEPENDS+=	tex-tetex>=3.0.27774nb1:../../print/tex-tetex

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/tetex

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/tetex

.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
