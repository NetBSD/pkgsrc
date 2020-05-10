# $NetBSD: Makefile,v 1.9 2020/05/10 04:31:48 markd Exp $

DISTNAME=	libertine
PKGNAME=	tex-${DISTNAME}-5.3.0.54583
PKGREVISION=	1
TEXLIVE_REV=	54583

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/libertine
COMMENT=	Use of Linux Libertine and Biolinum fonts with LaTeX
LICENSE=	gnu-gpl-v2 AND ofl-v1.1 AND lppl-1.3c

DEPENDS+=	tex-boondox-[0-9]*:../../fonts/tex-boondox
DEPENDS+=	tex-fontaxes-[0-9]*:../../print/tex-fontaxes
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-mweights-[0-9]*:../../print/tex-mweights
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

TEX_MAP_FILES+=	libertine.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
