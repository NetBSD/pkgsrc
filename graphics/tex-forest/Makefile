# $NetBSD: Makefile,v 1.1 2023/12/10 02:17:02 riastradh Exp $

DISTNAME=	forest
PKGNAME=	tex-${DISTNAME}-2.1.5
TEXLIVE_REV=	57398

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/forest
COMMENT=	Drawing (linguistic) trees
LICENSE=	lppl-1.3c

DEPENDS+=	tex-elocalloc-[0-9]*:../../print/tex-elocalloc
DEPENDS+=	tex-environ-[0-9]*:../../print/tex-environ
DEPENDS+=	tex-etoolbox-[0-9]*:../../print/tex-etoolbox
DEPENDS+=	tex-inlinedef-[0-9]*:../../print/tex-inlinedef
DEPENDS+=	tex-l3packages-[0-9]*:../../print/tex-l3packages
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-pgfopts-[0-9]*:../../print/tex-pgfopts

# catalogue-contact-repository https://github.com/sasozivanovic/forest

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
