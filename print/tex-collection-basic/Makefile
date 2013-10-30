# $NetBSD: Makefile,v 1.6 2013/10/30 06:49:54 dholland Exp $

DISTNAME=	collection-basic
PKGNAME=	tex-${DISTNAME}-2010.${TEXLIVE_REV}
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	# empty
TEXLIVE_REV=	20730

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Essential programs and files for TeX

DEPENDS+=	tex-amsfonts>=3.0:../../fonts/tex-amsfonts
DEPENDS+=	tex-bibtex>=0.99d:../../print/tex-bibtex
DEPENDS+=	tex-cm>=2009.15878:../../fonts/tex-cm
DEPENDS+=	tex-dvipdfm>=0.13.2dnb1:../../print/tex-dvipdfm
DEPENDS+=	tex-dvipdfmx>=2010:../../print/tex-dvipdfmx
DEPENDS+=	tex-dvipdfmx-def>=3.0i:../../print/tex-dvipdfmx-def
DEPENDS+=	tex-dvips>=2010:../../print/tex-dvips
DEPENDS+=	tex-enctex>=2009:../../print/tex-enctex
DEPENDS+=	tex-etex>=2.1:../../print/tex-etex
DEPENDS+=	tex-etex-pkg>=2.0:../../print/tex-etex-pkg
DEPENDS+=	tex-glyphlist>=2.0nb1:../../fonts/tex-glyphlist
DEPENDS+=	gsftopkk>=1.19.2nb2:../../fonts/gsftopkk
DEPENDS+=	tex-hyph-utf8>=2010:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base>=2010:../../print/tex-hyphen-base
DEPENDS+=	tex-ifluatex>=1.3:../../print/tex-ifluatex
DEPENDS+=	tex-ifxetex>=0.6:../../print/tex-ifxetex
DEPENDS+=	tex-kpathsea>=2010:../../print/tex-kpathsea
DEPENDS+=	${LUA_PKGPREFIX}-alt-getopt>=0.7.0:../../devel/lua-alt-getopt
DEPENDS+=	tex-luatex>=0.60.1:../../print/tex-luatex
DEPENDS+=	tex-makeindex>=2.12:../../textproc/tex-makeindex
DEPENDS+=	tex-metafont>=2009nb1:../../fonts/tex-metafont
DEPENDS+=	tex-mflogo>=2009:../../fonts/tex-mflogo
DEPENDS+=	tex-mfware>=2009:../../fonts/tex-mfware
DEPENDS+=	tex-misc>=2010:../../print/tex-misc
DEPENDS+=	tex-pdftex>=1.40.11nb1:../../print/tex-pdftex
DEPENDS+=	tex-plain>=3.141592653nb2:../../print/tex-plain
DEPENDS+=	dialog>=1.1.20100428:../../misc/dialog
DEPENDS+=	tex-tetex>=3.0.19695:../../print/tex-tetex
DEPENDS+=	tex-tex>=3.1415926:../../print/tex-tex
# texlive-tetex installs texconfig
DEPENDS+=	texlive-tetex>=2010:../../print/texlive-tetex
# texlive-msg-translations is not needed in pkgsrc.
DEPENDS+=	tex-texlive-scripts>=2010:../../print/tex-texlive-scripts
# texlive.infra is not needed in pkgsrc.
DEPENDS+=	tex-xdvi>=22.84.16nb1:../../print/tex-xdvi

META_PACKAGE=	yes

.include "../../lang/lua/luaversion.mk"
.include "../../mk/bsd.pkg.mk"
