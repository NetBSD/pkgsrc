# $NetBSD: Makefile,v 1.11 2026/03/26 08:54:00 markd Exp $

DISTNAME=	ebgaramond
PKGNAME=	tex-${DISTNAME}-2025
TEXLIVE_REV=	78251

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ebgaramond
COMMENT=	LaTeX support for EBGaramond fonts
LICENSE=	ofl-v1.1 AND lppl-1.3c

DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

TEX_MAP_FILES+=	EBGaramond.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
