# $NetBSD: Makefile,v 1.1 2026/04/03 01:59:23 markd Exp $

DISTNAME=	tikz-timing
PKGNAME=	tex-${DISTNAME}-0.7f
TEXLIVE_REV=	64967

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tikz-timing
COMMENT=	Easy generation of timing diagrams as TikZ pictures
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-svn-prov-[0-9]*:../../print/tex-svn-prov

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
