# $NetBSD: Makefile,v 1.8 2020/11/30 21:37:44 nikita Exp $

DISTNAME=	europasscv
PKGNAME=	tex-${DISTNAME}-2020-10-31.56829
TEXLIVE_REV=	56829

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/europasscv
COMMENT=	Unofficial class for the new version of the Europass curriculum vitae
LICENSE=	lppl-1.3c

DEPENDS+=	tex-colortbl-[0-9]*:../../print/tex-colortbl
DEPENDS+=	tex-enumitem-[0-9]*:../../print/tex-enumitem
DEPENDS+=	tex-fancyhdr-[0-9]*:../../print/tex-fancyhdr
DEPENDS+=	tex-geometry-[0-9]*:../../print/tex-geometry
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-setspace-[0-9]*:../../print/tex-setspace
DEPENDS+=	tex-soul-[0-9]*:../../print/tex-soul
DEPENDS+=	tex-tabu-[0-9]*:../../print/tex-tabu
DEPENDS+=	tex-totpages-[0-9]*:../../print/tex-totpages
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xifthen-[0-9}]*:../../devel/tex-xifthen

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
