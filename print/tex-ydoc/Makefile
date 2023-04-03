# $NetBSD: Makefile,v 1.4 2023/04/03 11:55:12 markd Exp $

DISTNAME=	ydoc
PKGNAME=	tex-${DISTNAME}-0.7alpha
TEXLIVE_REV=	64887

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ydoc
COMMENT=	Macros for documentation of LaTeX classes and packages
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-float-[0-9]*:../../print/tex-float
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-listings-[0-9]*:../../print/tex-listings
DEPENDS+=	tex-needspace-[0-9]*:../../print/tex-needspace
DEPENDS+=	tex-newverbs-[0-9]*:../../print/tex-newverbs
DEPENDS+=	tex-showexpl-[0-9]*:../../print/tex-showexpl
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
