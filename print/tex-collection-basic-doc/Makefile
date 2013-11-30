# $NetBSD: Makefile,v 1.5 2013/11/30 23:42:15 minskim Exp $

DISTNAME=	collection-basic-doc
PKGNAME=	tex-${DISTNAME}-2013
CATEGORIES=	print
MASTER_SITES=	# empty
TEXLIVE_REV=	30372

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Documentation for tex-collection-basic

DEPENDS+=	tex-amsfonts-doc-[0-9]*:../../fonts/tex-amsfonts-doc
DEPENDS+=	tex-bibtex-doc-[0-9]*:../../print/tex-bibtex-doc
DEPENDS+=	tex-cm-doc-[0-9]*:../../fonts/tex-cm-doc
DEPENDS+=	tex-dvipdfmx-doc-[0-9]*:../../print/tex-dvipdfmx-doc
# tex-dvipdfmx-def doesn't have a documentation package.
DEPENDS+=	tex-dvips-doc-[0-9]*:../../print/tex-dvips-doc
DEPENDS+=	tex-enctex-doc-[0-9]*:../../print/tex-enctex-doc
DEPENDS+=	tex-etex-doc-[0-9]*:../../print/tex-etex-doc
DEPENDS+=	tex-etex-pkg-doc-[0-9]*:../../print/tex-etex-pkg-doc
# tex-glyphlist doesn't have a documnetation package.
# gsftopk installs its documentation.
DEPENDS+=	tex-hyph-utf8-doc-[0-9]*:../../print/tex-hyph-utf8-doc
# tex-hyphen-base doesn't have a documentation package.
DEPENDS+=	tex-ifluatex-doc-[0-9]*:../../print/tex-ifluatex-doc
DEPENDS+=	tex-ifxetex-doc-[0-9]*:../../print/tex-ifxetex-doc
DEPENDS+=	tex-kpathsea-doc-[0-9]*:../../print/tex-kpathsea-doc
# lua-alt-getopt should install its documentation.
DEPENDS+=	tex-luatex-doc-[0-9]*:../../print/tex-luatex-doc
DEPENDS+=	tex-makeindex-doc-[0-9]*:../../textproc/tex-makeindex-doc
# tex-metafont's documentation is installed by web2c.
DEPENDS+=	tex-mflogo-doc-[0-9]*:../../fonts/tex-mflogo-doc
# tex-mfware's documentation is installed by web2c.
# tex-misc doesn't have a documentation package.
DEPENDS+=	tex-pdftex-doc-[0-9]*:../../print/tex-pdftex-doc
# tex-plain doesn't have a documentation package.
DEPENDS+=	tex-tetex-doc-[0-9]*:../../print/tex-tetex-doc
# tex-tex's documentation is installed by web2c.
DEPENDS+=	tex-texconfig-doc-[0-9]*:../../print/tex-texconfig-doc
DEPENDS+=	tex-texlive-common-doc-[0-9]*:../../print/tex-texlive-common-doc
DEPENDS+=	tex-texlive-docindex-doc-[0-9]*:../../print/tex-texlive-docindex-doc
DEPENDS+=	tex-texlive-en-doc-[0-9]*:../../print/tex-texlive-en-doc
# texlive-msg-translation is not needed in pkgsrc.
# texlive-scripts's documentation is not needed in pkgsrc.
# texlive.infra is not needed in pkgsrc.
# xdvi's documentation is installed by xdvik.

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
