# $NetBSD: Makefile,v 1.7 2019/12/06 19:30:11 markd Exp $

DISTNAME=	libertine
PKGNAME=	tex-${DISTNAME}-5.3.0.51174
PKGREVISION=	1
TEXLIVE_REV=	51174

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/libertine
COMMENT=	Use of Linux Libertine and Biolinum fonts with LaTeX
LICENSE=	gnu-gpl-v2 AND ofl-v1.1 AND lppl-1.3c

TEX_MAP_FILES+=	libertine.map

DEPENDS+=	tex-boondox-[0-9]*:../../fonts/tex-boondox
DEPENDS+=	tex-fontaxes-[0-9]*:../../print/tex-fontaxes
DEPENDS+=	tex-mweights-[0-9]*:../../print/tex-mweights

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
