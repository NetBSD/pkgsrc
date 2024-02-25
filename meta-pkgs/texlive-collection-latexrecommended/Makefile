# $NetBSD: Makefile,v 1.22 2024/02/25 19:37:14 markd Exp $

DISTNAME=	collection-latexrecommended
PKGNAME=	texlive-${DISTNAME}-2023.69888
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	69888

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	LaTeX recommended packages

META_PACKAGE=	yes

DEPENDS+=	texlive-collection-latex>=2014:../../meta-pkgs/texlive-collection-latex

.include "../../mk/bsd.prefs.mk"

DEPENDS+=	tex-anysize-[0-9]*:../../print/tex-anysize
DEPENDS+=	tex-attachfile2-[0-9]*:../../print/tex-attachfile2
DEPENDS+=	tex-beamer-[0-9]*:../../print/tex-beamer
DEPENDS+=	tex-booktabs-[0-9]*:../../print/tex-booktabs
DEPENDS+=	tex-breqn-[0-9]*:../../print/tex-breqn
DEPENDS+=	tex-caption-[0-9]*:../../print/tex-caption
DEPENDS+=	tex-cite-[0-9]*:../../print/tex-cite
DEPENDS+=	tex-cmap-[0-9]*:../../print/tex-cmap
DEPENDS+=	tex-crop-[0-9]*:../../print/tex-crop
DEPENDS+=	tex-ctable-[0-9]*:../../print/tex-ctable
DEPENDS+=	tex-eso-pic-[0-9]*:../../print/tex-eso-pic
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-euenc-[0-9]*:../../fonts/tex-euenc
DEPENDS+=	tex-euler-[0-9]*:../../print/tex-euler
DEPENDS+=	tex-everysel-[0-9]*:../../print/tex-everysel
DEPENDS+=	tex-everyshi-[0-9]*:../../print/tex-everyshi
DEPENDS+=	tex-extsizes-[0-9]*:../../print/tex-extsizes
DEPENDS+=	tex-fancybox-[0-9]*:../../print/tex-fancybox
DEPENDS+=	tex-fancyref-[0-9]*:../../print/tex-fancyref
DEPENDS+=	tex-fancyvrb-[0-9]*:../../print/tex-fancyvrb
DEPENDS+=	tex-filehook-[0-9]*:../../print/tex-filehook
DEPENDS+=	tex-float-[0-9]*:../../print/tex-float
DEPENDS+=	tex-fontspec-[0-9]*:../../fonts/tex-fontspec
DEPENDS+=	tex-footnotehyper-[0-9]*:../../print/tex-footnotehyper
DEPENDS+=	tex-fp-[0-9]*:../../math/tex-fp
DEPENDS+=	tex-grffile-[0-9]*:../../print/tex-grffile
DEPENDS+=	tex-hologo-[0-9]*:../../print/tex-hologo
DEPENDS+=	tex-index-[0-9]*:../../print/tex-index
DEPENDS+=	tex-infwarerr-[0-9]*:../../print/tex-infwarerr
DEPENDS+=	tex-jknapltx-[0-9]*:../../print/tex-jknapltx
DEPENDS+=	tex-koma-script-[0-9]*:../../print/tex-koma-script
DEPENDS+=	tex-l3experimental-[0-9]*:../../devel/tex-l3experimental
DEPENDS+=	tex-latexbug-[0-9]*:../../devel/tex-latexbug
DEPENDS+=	tex-lineno-[0-9]*:../../print/tex-lineno
DEPENDS+=	tex-listings-[0-9]*:../../print/tex-listings
.if empty(MACHINE_PLATFORM:MSunOS-*-sparc*) # PR pkg/55741
DEPENDS+=	tex-lwarp-[0-9]*:../../textproc/tex-lwarp
.endif
DEPENDS+=	tex-mathspec-[0-9]*:../../math/tex-mathspec
DEPENDS+=	tex-mathtools-[0-9]*:../../print/tex-mathtools
DEPENDS+=	tex-mdwtools-[0-9]*:../../print/tex-mdwtools
DEPENDS+=	tex-memoir-[0-9]*:../../print/tex-memoir
DEPENDS+=	tex-metalogo-[0-9]*:../../print/tex-metalogo
DEPENDS+=	tex-microtype-[0-9]*:../../print/tex-microtype
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms
DEPENDS+=	tex-newfloat-[0-9]*:../../print/tex-newfloat
DEPENDS+=	tex-ntgclass-[0-9]*:../../print/tex-ntgclass
DEPENDS+=	tex-parskip-[0-9]*:../../print/tex-parskip
DEPENDS+=	tex-pdfcolfoot-[0-9]*:../../print/tex-pdfcolfoot
DEPENDS+=	tex-pdflscape-[0-9]*:../../print/tex-pdflscape
DEPENDS+=	tex-pdfmanagement-testphase-[0-9]*:../../print/tex-pdfmanagement-testphase
DEPENDS+=	tex-pdfpages-[0-9]*:../../print/tex-pdfpages
DEPENDS+=	tex-polyglossia-[0-9]*:../../print/tex-polyglossia
DEPENDS+=	tex-psfrag-[0-9]*:../../print/tex-psfrag
DEPENDS+=	tex-ragged2e-[0-9]*:../../print/tex-ragged2e
DEPENDS+=	tex-rcs-[0-9]*:../../print/tex-rcs
DEPENDS+=	tex-sansmath-[0-9]*:../../print/tex-sansmath
DEPENDS+=	tex-section-[0-9]*:../../print/tex-section
DEPENDS+=	tex-seminar-[0-9]*:../../print/tex-seminar
DEPENDS+=	tex-sepnum-[0-9]*:../../print/tex-sepnum
DEPENDS+=	tex-setspace-[0-9]*:../../print/tex-setspace
DEPENDS+=	tex-subfig-[0-9]*:../../print/tex-subfig
DEPENDS+=	tex-textcase-[0-9]*:../../print/tex-textcase
DEPENDS+=	tex-thumbpdf-[0-9]*:../../print/tex-thumbpdf
DEPENDS+=	tex-translator-[0-9]*:../../print/tex-translator
DEPENDS+=	tex-typehtml-[0-9]*:../../print/tex-typehtml
DEPENDS+=	tex-ucharcat-[0-9]*:../../print/tex-ucharcat
DEPENDS+=	tex-underscore-[0-9]*:../../print/tex-underscore
DEPENDS+=	tex-unicode-math-[0-9]*:../../math/tex-unicode-math
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xfrac-[0-9]*:../../print/tex-xfrac
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
DEPENDS+=	tex-xltxtra-[0-9]*:../../print/tex-xltxtra
DEPENDS+=	tex-xunicode-[0-9]*:../../print/tex-xunicode

.include "../../mk/bsd.pkg.mk"
