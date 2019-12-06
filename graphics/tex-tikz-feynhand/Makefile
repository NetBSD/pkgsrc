# $NetBSD: Makefile,v 1.2 2019/12/06 20:04:39 markd Exp $

DISTNAME=	tikz-feynhand
PKGNAME=	tex-${DISTNAME}-1.0.0
TEXLIVE_REV=	46502

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tikz-feynhand
COMMENT=	Feynman diagrams with TikZ
LICENSE=	gnu-gpl-v3

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-pgfopts-[0-9]*:../../devel/tex-pgfopts

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
