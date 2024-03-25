# $NetBSD: Makefile,v 1.30 2024/03/25 10:58:32 markd Exp $

DISTNAME=	collection-binextra
PKGNAME=	texlive-${DISTNAME}-2024pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	70681

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	TeX auxiliary programs

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-a2ping-[0-9]*:../../graphics/tex-a2ping
# depend adhocfilelist
# depend arara
# XXX asymptote conflicts with other packages by requiring ghostscript-agpl
#DEPENDS+=	asymptote-[0-9]*:../../graphics/asymptote
DEPENDS+=	bibtex8-[0-9]*:../../print/bibtex8
DEPENDS+=	bibtexu-[0-9]*:../../print/bibtexu
# depend bundledoc
# depend checklistings
# depend chklref
DEPENDS+=	chktex-[0-9]*:../../print/chktex
# depend clojure-pamphlet
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
# depend digestif
# depend dtl
# depend dtxgen
DEPENDS+=	dvi2tty-[0-9]*:../../converters/dvi2tty
# depend dviasm
# depend dvicopy
DEPENDS+=	dvidvi-[0-9]*:../../print/dvidvi
# depend dviinfox
DEPENDS+=	dviljk-[0-9]*:../../print/dviljk
# depend dviout-util
DEPENDS+=	dvipng-[0-9]*:../../graphics/dvipng
# depend dvipos
DEPENDS+=	dvisvgm-[0-9]*:../../converters/dvisvgm
# depend easydtx
# depend findhyph
# depend fragmaster
# depend git-latexdiff
DEPENDS+=	gsftopkk>=1.19.2nb4:../../fonts/gsftopkk
# depend hook-pre-commit-pkg
# depend installfont
# depend ketcindy
# depend l3sys-query
DEPENDS+=	lacheck-[0-9]*:../../print/lacheck
# depend latex-git-log
# depend latex-papersize
# depend latex2man
# depend latex2nemeth
DEPENDS+=	tex-latexdiff-[0-9]*:../../textproc/tex-latexdiff
# depend latexfileversion
# depend latexindent
DEPENDS+=	latexmk-[0-9]*:../../print/latexmk
# depend latexpand
# depend light-latex-make
# depend listings-ext
# depend ltxfileinfo
# depend ltximg
DEPENDS+=	tex-make4ht-[0-9]*:../../print/tex-make4ht
# depend match_parens
# depend mflua
# depend mkjobtexmf
# depend optexcount
# patgen entirely included in web2c
# depend pdfbook2
DEPENDS+=	tex-pdfcrop-[0-9]*:../../graphics/tex-pdfcrop
DEPENDS+=	pdfjam-[0-9]*:../../print/pdfjam
# depend pdflatexpicscale
# depend pdftex-quiet
# depend pdftosrc
# depend pdfxup
# depend pfarrei
DEPENDS+=	tex-pkfix-[0-9]*:../../print/tex-pkfix
# depend pkfix-helper
# depend ppmcheckpdf
# depend purifyeps
# depend pythontex
# depend runtexshebang
DEPENDS+=	seetexk-[0-9]*:../../print/seetexk
# depend spix
# depend srcredact
# depend sty2dtx
# depend synctex
DEPENDS+=	tex-tex4ebook-[0-9]*:../../print/tex-tex4ebook
# depend texaccents
# depend texblend
# depend texcount
# depend texdef
# depend texdiff
# depend texdirflatten
DEPENDS+=	tex-texdoc-[0-9]*:../../print/tex-texdoc
DEPENDS+=	tex-texdoctk-[0-9]*:../../print/tex-texdoctk
# depend texfot
DEPENDS+=	tex-texlive-scripts-extra-[0-9]*:../../print/tex-texlive-scripts-extra
# depend texliveonfly
# depend texloganalyser
# depend texlogfilter
# depend texlogsieve
# depend texosquery
# depend texplate
# texware entirely included in web2c
# tie entirely included in web2c
# depend tlcockpit
# depend tpic2pdftex
# depend typeoutfileinfo
DEPENDS+=	upmendex-[0-9]*:../../textproc/upmendex
# web entirely included in web2c
# depend xindex
DEPENDS+=	tex-xindy-[0-9]*:../../textproc/tex-xindy
DEPENDS+=	xpdfopen-[0-9]*:../../print/xpdfopen

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
