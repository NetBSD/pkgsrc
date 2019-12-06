# $NetBSD: Makefile,v 1.3 2019/12/06 20:23:41 markd Exp $

DISTNAME=	verbasef
PKGNAME=	tex-${DISTNAME}-1.1
TEXLIVE_REV=	21922

MAINTAINER=	minskim@NetBSD.org
COMMENT=	VERBatim Automatic Splitting of External Files
LICENSE=	gnu-gpl-v2

CONFLICTS=	tex-ltxmisc<2010.21927
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-ltxmisc>=2010.21927:../../print/tex-ltxmisc
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-here-[0-9]*:../../print/tex-here

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
