# $NetBSD: Makefile,v 1.3 2020/04/27 02:08:14 markd Exp $

DISTNAME=	tikz-feynhand
PKGNAME=	tex-${DISTNAME}-1.1.0
TEXLIVE_REV=	51915

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tikz-feynhand
COMMENT=	Feynman diagrams with TikZ
LICENSE=	gnu-gpl-v3

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-pgfopts-[0-9]*:../../devel/tex-pgfopts

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
