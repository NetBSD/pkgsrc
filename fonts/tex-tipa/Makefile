# $NetBSD: Makefile,v 1.8 2020/05/10 04:31:55 markd Exp $

DISTNAME=	tipa
PKGNAME=	tex-${DISTNAME}-1.3pl29349
PKGREVISION=	1
TEXLIVE_REV=	29349

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Fonts and macros for IPA phonetics characters
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

TEX_MIXEDMAP_FILES+=	tipa.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
