# $NetBSD: Makefile,v 1.14 2019/01/28 09:39:53 markd Exp $

DISTNAME=	collection-binextra
PKGNAME=	texlive-${DISTNAME}-2018pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	49312

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	TeX auxiliary programs

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-a2ping-[0-9]*:../../graphics/tex-a2ping
# depend adhocfilelist
# depend arara
# XXX asymptote conflicts with other packages by requiring ghostscript-agpl
#DEPENDS+=	asymptote-[0-9]*:../../graphics/asymptote
DEPENDS+=	tex-bibtex8-[0-9]*:../../print/tex-bibtex8
# depend bibtexu
# depend bundledoc
# depend checklistings
DEPENDS+=	chktex-[0-9]*:../../print/chktex
# depend cluttex
# depend ctan-o-mat
# depend ctan_chk
# depend ctanbib
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
# depend dviinfox
DEPENDS+=	dviljk-[0-9]*:../../print/dviljk
DEPENDS+=	dvipng-[0-9]*:../../graphics/dvipng
# depend dvipos
# depend dvisvgm
# depend findhyph
# depend fragmaster
# depend hook-pre-commit-pkg
# depend hyphenex
# depend installfont
# depend ketcindy
DEPENDS+=	lacheck-[0-9]*:../../print/lacheck
# depend latex-git-log
# depend latex-papersize
# depend latex2man
# depend latex2nemeth
DEPENDS+=	tex-latexdiff-[0-9]*:../../textproc/tex-latexdiff
# depend latexfileversion
DEPENDS+=	latexmk-[0-9]*:../../print/latexmk
# depend latexpand
# depend latexindent
# depend ltxfileinfo
# depend ltximg
# depend listings-ext
DEPENDS+=	tex-make4ht-[0-9]*:../../print/tex-make4ht
# depend match_parens
# depend mflua
# depend mkjobtexmf
# patgen entirely included in web2c
# depend pdfbook2
DEPENDS+=	tex-pdfcrop-[0-9]*:../../graphics/tex-pdfcrop
DEPENDS+=	pdfjam-[0-9]*:../../print/pdfjam
# depend pdflatexpicscale
# depend pdftex-quiet
DEPENDS+=	tex-pdftools-[0-9]*:../../print/tex-pdftools
# depend pdfxup
# depend pfarrei
DEPENDS+=	tex-pkfix-[0-9]*:../../print/tex-pkfix
# depend pkfix-helper
# depend purifyeps
# depend pythontex
DEPENDS+=	seetexk-[0-9]*:../../print/seetexk
# depend srcredact
# depend sty2dtx
# depend synctex
DEPENDS+=	tex-tex4ebook-[0-9]*:../../print/tex-tex4ebook
# depend texcount
# depend texdef
# depend texdiff
# depend texdirflatten
DEPENDS+=	tex-texdoc-[0-9]*:../../print/tex-texdoc
# depend texdoctk
# depend texfot
# depend texliveonfly
# depend texloganalyser
# depend texosquery
# texware entirely included in web2c
# tie entirely included in web2c
# depend tlcockpit
# depend tlshell
# depend tpic2pdftex
# depend typeoutfileinfo
# web entirely included in web2c
# depend xindex
DEPENDS+=	tex-xindy-[0-9]*:../../textproc/tex-xindy

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
