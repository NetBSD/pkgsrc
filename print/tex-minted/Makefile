# $NetBSD: Makefile,v 1.17 2024/02/14 19:41:04 markd Exp $

DISTNAME=	minted
PKGNAME=	tex-${DISTNAME}-2.9
TEXLIVE_REV=	69163

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/minted
COMMENT=	Highlighted source code for LaTeX
LICENSE=	lppl-1.3c AND modified-bsd

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
DEPENDS+=	tex-newfloat-[0-9]*:../../print/tex-newfloat
DEPENDS+=	tex-pdftexcmds-[0-9]*:../../print/tex-pdftexcmds
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-upquote-[0-9]*:../../print/tex-upquote
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xstring-[0-9]*:../../print/tex-xstring
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
