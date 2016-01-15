# $NetBSD: Makefile,v 1.5 2016/01/15 08:59:30 wiz Exp $

DISTNAME=	collection-binextra
PKGNAME=	texlive-${DISTNAME}-2014pre4
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	37751

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	TeX auxiliary programs

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-a2ping-[0-9]*:../../graphics/tex-a2ping
# depend adhocfilelist
# depend arara
DEPENDS+=	asymptote-[0-9]*:../../graphics/asymptote
DEPENDS+=	tex-bibtex8-[0-9]*:../../print/tex-bibtex8
# depend bibtexu
# depend bundledoc
DEPENDS+=	chktex-[0-9]*:../../print/chktex
# depend ctan_chk
# depend ctanify
# depend ctanupload
# ctie entirely included in web2c
DEPENDS+=	tex-cweb-[0-9]*:../../print/tex-cweb
# depend de-macro
DEPENDS+=	detex-[0-9]*:../../textproc/detex
# depend dtl
# depend dtxgen
DEPENDS+=	dvi2tty-[0-9]*:../../converters/dvi2tty
# depend dviasm
# depend dvicopy
DEPENDS+=	dvidvi-[0-9]*:../../print/dvidvi
DEPENDS+=	dviljk-[0-9]*:../../print/dviljk
DEPENDS+=	dvipng-[0-9]*:../../graphics/dvipng
# depend dvipos
# depend dvisvgm
# depend findhyph
# depend fragmaster
# depend hook-pre-commit-pkg
# depend hyphenex
# depend installfont
DEPENDS+=	lacheck-[0-9]*:../../print/lacheck
# depend latex-git-log
# depend latex2man
DEPENDS+=	tex-latexdiff-[0-9]*:../../textproc/tex-latexdiff
# depend latexfileversion
DEPENDS+=	latexmk-[0-9]*:../../print/latexmk
# depend latexpand
# depend latexindent
# depend ltxfileinfo
# depend ltximg
# depend listings-ext
# depend make4ht
# depend match_parens
# depend mkjobtexmf
# patgen entirely included in web2c
# depend pdfbook2
DEPENDS+=	tex-pdfcrop-[0-9]*:../../graphics/tex-pdfcrop
DEPENDS+=	pdfjam-[0-9]*:../../print/pdfjam
DEPENDS+=	tex-pdftools-[0-9]*:../../print/tex-pdftools
# depend pfarrei
DEPENDS+=	tex-pkfix-[0-9]*:../../print/tex-pkfix
# depend pkfix-helper
# depend purifyeps
# depend pythontex
DEPENDS+=	seetexk-[0-9]*:../../print/seetexk
# depend sty2dtx
# depend synctex
# depend tex4ebook
# depend texcount
# depend texdef
# depend texdiff
# depend texdirflatten
DEPENDS+=	tex-texdoc-[0-9]*:../../print/tex-texdoc
# depend texfot
# depend texliveonfly
# depend texloganalyser
# texware entirely included in web2c
# tie entirely included in web2c
# depend tpic2pdftex
# depend typeoutfileinfo
# web entirely included in web2c
# depend xindy

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
