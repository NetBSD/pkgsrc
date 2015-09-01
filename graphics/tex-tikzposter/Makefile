# $NetBSD: Makefile,v 1.1 2015/09/01 21:07:29 markd Exp $

DISTNAME=	tikzposter
PKGNAME=	tex-${DISTNAME}-2.0
TEXLIVE_REV=	32732

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/tikzposter
COMMENT=	Create scientific posters using TikZ
LICENSE=	lppl-1.2

DEPENDS+=	tex-ae-[0-9]*:../../fonts/tex-ae
DEPENDS+=	tex-a0poster-[0-9]*:../../print/tex-a0poster
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-extsizes-[0-9]*:../../print/tex-extsizes
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
DEPENDS+=	tex-xstring-[0-9]*:../../print/tex-xstring

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
