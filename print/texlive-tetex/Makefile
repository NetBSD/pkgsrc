# $NetBSD: Makefile,v 1.13 2012/10/14 21:26:23 minskim Exp $

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

FILES_SUBST+=	UPDMAP_SYS=${PREFIX}/bin/updmap-sys

INSTALLATION_DIRS+=	share/texmf/web2c

TEX_TEXMF_DIRS+=	${PKG_SYSCONFDIR}
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/kpathsea/texmf.mk"
.include "../../mk/bsd.pkg.mk"
