# $NetBSD: Makefile,v 1.20 2024/03/21 20:00:51 markd Exp $

DISTNAME=	collection-basic
PKGNAME=	texlive-${DISTNAME}-2024
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	59159

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Essential programs and files for TeX

DEPENDS+=	tex-amsfonts>=3.04:../../fonts/tex-amsfonts
DEPENDS+=	tex-bibtex>=0.99dnb1:../../print/tex-bibtex
DEPENDS+=	tex-cm>=2013:../../fonts/tex-cm
DEPENDS+=	tex-colorprofiles-[0-9]*:../../print/tex-colorprofiles
DEPENDS+=	tex-dvipdfmx>=2013:../../print/tex-dvipdfmx
DEPENDS+=	tex-dvips>=2013:../../print/tex-dvips
DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
DEPENDS+=	tex-enctex>=2013:../../print/tex-enctex
DEPENDS+=	tex-etex>=2.1.31600:../../print/tex-etex
DEPENDS+=	tex-etex-pkg>=2.0:../../print/tex-etex-pkg
DEPENDS+=	tex-glyphlist>=2.95:../../fonts/tex-glyphlist
DEPENDS+=	tex-graphics-def>=2016:../../print/tex-graphics-def
DEPENDS+=	tex-hyph-utf8>=2013:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base>=2013:../../print/tex-hyphen-base
DEPENDS+=	tex-hyphenex-[0-9]*:../../print/tex-hyphenex
DEPENDS+=	tex-ifplatform-[0-9]*:../../print/tex-ifplatform
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-knuth-lib>=2014:../../fonts/tex-knuth-lib
DEPENDS+=	tex-knuth-local>=2014:../../fonts/tex-knuth-local
DEPENDS+=	tex-kpathsea>=2013:../../print/tex-kpathsea
DEPENDS+=	${LUA_PKGPREFIX}-alt-getopt>=0.7.0nb1:../../devel/lua-alt-getopt
DEPENDS+=	tex-luahbtex-[0-9]*:../../print/tex-luahbtex
DEPENDS+=	tex-luatex>=0.70.1pl30581:../../print/tex-luatex
DEPENDS+=	tex-makeindex>=2.12nb1:../../textproc/tex-makeindex
DEPENDS+=	tex-metafont>=2013:../../fonts/tex-metafont
DEPENDS+=	tex-mflogo>=2009nb1:../../fonts/tex-mflogo
DEPENDS+=	tex-mfware>=2013:../../fonts/tex-mfware
DEPENDS+=	tex-modes-[0-9]*:../../fonts/tex-modes
DEPENDS+=	tex-pdftex>=1.40.11pl32132:../../print/tex-pdftex
DEPENDS+=	tex-plain>=3.141592653.26647:../../print/tex-plain
DEPENDS+=	tex-tex>=3.1415926:../../print/tex-tex
DEPENDS+=	tex-tex-ini-files-[0-9]*:../../print/tex-tex-ini-files
# texlive-msg-translations is not needed in pkgsrc.
DEPENDS+=	tex-texlive-scripts>=2013:../../print/tex-texlive-scripts
DEPENDS+=	tex-texlive.infra>=2013:../../print/tex-texlive.infra
DEPENDS+=	tex-tlshell-[0-9]*:../../devel/tex-tlshell
DEPENDS+=	tex-unicode-data-[0-9]*:../../print/tex-unicode-data
DEPENDS+=	tex-xdvi>=22.87:../../print/tex-xdvi

META_PACKAGE=	yes

.include "options.mk"

.include "../../lang/lua/luaversion.mk"
.include "../../mk/bsd.pkg.mk"
