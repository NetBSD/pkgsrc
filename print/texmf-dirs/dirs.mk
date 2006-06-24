# $NetBSD: dirs.mk,v 1.8 2006/06/24 10:39:32 hira Exp $
#
# This file is intended to be included by mk/dirs.mk, not directly by packages.
#

.if !defined(DIRS_TEXMF_MK)
DIRS_TEXMF_MK=		# defined

TEXMF_DIRS=	bibtex
TEXMF_DIRS+=	bibtex/bib
TEXMF_DIRS+=	bibtex/bst
TEXMF_DIRS+=	doc
TEXMF_DIRS+=	doc/bibtex
TEXMF_DIRS+=	doc/fonts
TEXMF_DIRS+=	doc/latex
TEXMF_DIRS+=	dvipdfm
TEXMF_DIRS+=	fonts
TEXMF_DIRS+=	fonts/afm
TEXMF_DIRS+=	fonts/cmap
TEXMF_DIRS+=	fonts/enc
TEXMF_DIRS+=	fonts/enc/pdftex
TEXMF_DIRS+=	fonts/map
TEXMF_DIRS+=	fonts/map/dvipdfm
TEXMF_DIRS+=	fonts/map/dvips
TEXMF_DIRS+=	fonts/map/pdftex
TEXMF_DIRS+=	fonts/ofm
TEXMF_DIRS+=	fonts/ovf
TEXMF_DIRS+=	fonts/ovp
TEXMF_DIRS+=	fonts/source
TEXMF_DIRS+=	fonts/tfm
TEXMF_DIRS+=	fonts/tfm/public
TEXMF_DIRS+=	fonts/truetype
TEXMF_DIRS+=	fonts/type1
TEXMF_DIRS+=	fonts/type1/public
TEXMF_DIRS+=	fonts/vf
TEXMF_DIRS+=	makeindex
TEXMF_DIRS+=	omega
TEXMF_DIRS+=	omega/ocp
TEXMF_DIRS+=	omega/otp
TEXMF_DIRS+=	tex
TEXMF_DIRS+=	tex/lambda
TEXMF_DIRS+=	tex/latex
TEXMF_DIRS+=	web2c

.if defined(_USE_TEXMF_DIRS) && !empty(_USE_TEXMF_DIRS)
DEPENDS+=	texmf-dirs>=${_USE_TEXMF_DIRS}:../../print/texmf-dirs

.  for dir in ${TEXMF_DIRS}
PRINT_PLIST_AWK+=	/^@dirrm \$${PKG_LOCALTEXMFPREFIX}\/${dir:S|/|\\/|g}$$/ \
			{ print "@comment In texmf-dirs: " $$0; next; }
.  endfor
.endif

.endif			# !defined(DIRS_TEXMF_MK)
