# $NetBSD: Makefile,v 1.14 2023/04/01 12:07:38 markd Exp $

DISTNAME=	minted
PKGNAME=	tex-${DISTNAME}-2.7
TEXLIVE_REV=	65252

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/minted
COMMENT=	Highlighted source code for LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-catchfile-[0-9]*:../../print/tex-catchfile
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-fancyvrb-[0-9]*:../../print/tex-fancyvrb
DEPENDS+=	tex-float-[0-9]*:../../print/tex-float
DEPENDS+=	tex-framed-[0-9]*:../../print/tex-framed
DEPENDS+=	tex-fvextra-[0-9]*:../../print/tex-fvextra
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-ifplatform-[0-9]*:../../print/tex-ifplatform
DEPENDS+=	tex-kvoptions-[0-9]*:../../print/tex-kvoptions
DEPENDS+=	tex-lineno-[0-9]*:../../print/tex-lineno
DEPENDS+=	tex-pdftexcmds-[0-9]*:../../print/tex-pdftexcmds
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-upquote-[0-9]*:../../print/tex-upquote
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xstring-[0-9]*:../../print/tex-xstring

PYTHON_VERSIONED_DEPENDENCIES=	pygments

.include "../../lang/python/pyversion.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
