# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:49 markd Exp $

DISTNAME=	mathdesign
PKGNAME=	tex-${DISTNAME}-2.31
PKGREVISION=	1
TEXLIVE_REV=	31639

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Mathematical fonts to fit with particular text fonts
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

TEX_MAP_FILES+=	mdbch.map
TEX_MAP_FILES+=	mdgreek.map
TEX_MAP_FILES+=	mdici.map
TEX_MAP_FILES+=	mdpgd.map
TEX_MAP_FILES+=	mdpus.map
TEX_MAP_FILES+=	mdput.map
TEX_MAP_FILES+=	mdugm.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
