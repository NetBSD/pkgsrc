# $NetBSD: Makefile,v 1.1 2015/05/06 10:41:42 markd Exp $

DISTNAME=	collection-binextra
PKGNAME=	texlive-${DISTNAME}-2014pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	36355

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	TeX auxiliary programs

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-a2ping-[0-9]*:../../graphics/tex-a2ping
# depend adhocfilelist
# depend arara
# depend asymptote
DEPENDS+=	tex-bibtex8-[0-9]*:../../print/tex-bibtex8
# depend bibtexu
# depend bundledoc
# depend chktex
# depend ctan_chk
# depend ctanify
# depend ctanupload
# depend ctie
DEPENDS+=	tex-cweb-[0-9]*:../../print/tex-cweb
# depend de-macro
DEPENDS+=	detex-[0-9]*:../../textproc/detex
# depend dtl
# depend dtxgen
# depend dvi2tty
# depend dviasm
# depend dvicopy
# depend dvidvi
DEPENDS+=	dviljk-[0-9]*:../../print/dviljk
DEPENDS+=	dvipng-[0-9]*:../../graphics/dvipng
# depend dvipos
# depend dvisvgm
# depend findhyph
# depend fragmaster
# depend hook-pre-commit-pkg
# depend hyphenex
# depend installfont
# depend lacheck
# depend latex-git-log
# depend latex2man
# depend latexdiff
# depend latexfileversion
# depend latexmk
# depend latexpand
# depend latexindent
# depend ltxfileinfo
# depend ltximg
# depend listings-ext
# depend match_parens
# depend mkjobtexmf
# depend patgen
DEPENDS+=	tex-pdfcrop-[0-9]*:../../graphics/tex-pdfcrop
# depend pdfjam
DEPENDS+=	tex-pdftools-[0-9]*:../../print/tex-pdftools
# depend pfarrei
DEPENDS+=	tex-pkfix-[0-9]*:../../print/tex-pkfix
# depend pkfix-helper
# depend purifyeps
# depend pythontex
# depend seetexk
# depend sty2dtx
# depend synctex
# depend texcount
# depend texdef
# depend texdiff
# depend texdirflatten
DEPENDS+=	tex-texdoc-[0-9]*:../../print/tex-texdoc
# depend texfot
# depend texliveonfly
# depend texloganalyser
# depend texware
# depend tie
# depend tpic2pdftex
# depend typeoutfileinfo
# depend web
# depend xindy

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
