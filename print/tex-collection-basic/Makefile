# $NetBSD: Makefile,v 1.8 2013/11/30 23:42:15 minskim Exp $

DISTNAME=	collection-basic
PKGNAME=	tex-${DISTNAME}-2013
CATEGORIES=	print
MASTER_SITES=	# empty
TEXLIVE_REV=	30372

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Essential programs and files for TeX

DEPENDS+=	tex-texlive.infra>=2013:../../print/tex-texlive.infra
DEPENDS+=	tex-amsfonts>=3.04:../../fonts/tex-amsfonts
DEPENDS+=	tex-bibtex>=0.99dnb1:../../print/tex-bibtex
DEPENDS+=	tex-cm>=2013:../../fonts/tex-cm
DEPENDS+=	tex-dvipdfmx>=2013:../../print/tex-dvipdfmx
DEPENDS+=	tex-dvipdfmx-def>=3.3:../../print/tex-dvipdfmx-def
DEPENDS+=	tex-dvips>=2013:../../print/tex-dvips
DEPENDS+=	tex-enctex>=2013:../../print/tex-enctex
DEPENDS+=	tex-etex>=2.1.31600:../../print/tex-etex
DEPENDS+=	tex-etex-pkg>=2.0:../../print/tex-etex-pkg
DEPENDS+=	tex-glyphlist>=2.95:../../fonts/tex-glyphlist
DEPENDS+=	gsftopkk>=1.19.2nb4:../../fonts/gsftopkk
DEPENDS+=	tex-hyph-utf8>=2013:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base>=2013:../../print/tex-hyphen-base
DEPENDS+=	tex-ifluatex>=1.3pl26725:../../print/tex-ifluatex
DEPENDS+=	tex-ifxetex>=0.6:../../print/tex-ifxetex
DEPENDS+=	tex-kpathsea>=2013:../../print/tex-kpathsea
DEPENDS+=	${LUA_PKGPREFIX}-alt-getopt>=0.7.0nb1:../../devel/lua-alt-getopt
DEPENDS+=	tex-luatex>=0.70.1pl30581:../../print/tex-luatex
DEPENDS+=	tex-makeindex>=2.12nb1:../../textproc/tex-makeindex
DEPENDS+=	tex-metafont>=2013:../../fonts/tex-metafont
DEPENDS+=	tex-mflogo>=2009nb1:../../fonts/tex-mflogo
DEPENDS+=	tex-mfware>=2013:../../fonts/tex-mfware
DEPENDS+=	tex-misc>=2012:../../print/tex-misc
DEPENDS+=	tex-pdftex>=1.40.11pl32132:../../print/tex-pdftex
DEPENDS+=	tex-plain>=3.141592653.26647:../../print/tex-plain
DEPENDS+=	tex-tetex>=3.0.32132:../../print/tex-tetex
DEPENDS+=	tex-tex>=3.1415926:../../print/tex-tex
DEPENDS+=	tex-texconfig>=2013:../../print/tex-texconfig
DEPENDS+=	tex-texlive-docindex>=2013:../../print/tex-texlive-docindex
# texlive-msg-translations is not needed in pkgsrc.
DEPENDS+=	tex-texlive-scripts>=2013:../../print/tex-texlive-scripts
DEPENDS+=	tex-xdvi>=22.86:../../print/tex-xdvi

META_PACKAGE=	yes

.include "../../lang/lua/luaversion.mk"
.include "../../mk/bsd.pkg.mk"
