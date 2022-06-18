# $NetBSD: Makefile,v 1.42 2022/06/18 21:20:40 bacon Exp $

DISTNAME=	dblatex-0.3.10
PKGREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dblatex/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dblatex.sourceforge.net/
COMMENT=	DocBook to LaTeX Publishing
LICENSE=	gnu-gpl-v2

DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	makeindexk-[0-9]*:../../textproc/makeindexk
DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
DEPENDS+=	texlive-collection-latex-[0-9]*:../../meta-pkgs/texlive-collection-latex
DEPENDS+=	tex-iftex>=1.0d:../../print/tex-iftex
DEPENDS+=	tex-anysize-[0-9]*:../../print/tex-anysize
DEPENDS+=	tex-appendix-[0-9]*:../../print/tex-appendix
DEPENDS+=	tex-bookmark-[0-9]*:../../print/tex-bookmark
DEPENDS+=	tex-changebar-[0-9]*:../../print/tex-changebar
DEPENDS+=	tex-fancybox-[0-9]*:../../print/tex-fancybox
DEPENDS+=	tex-fancyvrb-[0-9]*:../../print/tex-fancyvrb
DEPENDS+=	tex-float-[0-9]*:../../print/tex-float
DEPENDS+=	tex-footmisc-[0-9]*:../../print/tex-footmisc
DEPENDS+=	tex-jknapltx-[0-9]*:../../print/tex-jknapltx
DEPENDS+=	tex-listings-[0-9]*:../../print/tex-listings
DEPENDS+=	tex-multirow-[0-9]*:../../print/tex-multirow
DEPENDS+=	tex-overpic-[0-9]*:../../print/tex-overpic
DEPENDS+=	tex-pdflscape-[0-9]*:../../print/tex-pdflscape
DEPENDS+=	tex-pdfpages-[0-9]*:../../print/tex-pdfpages
DEPENDS+=	tex-rotating-[0-9]*:../../print/tex-rotating
DEPENDS+=	tex-stmaryrd-[0-9]*:../../fonts/tex-stmaryrd
DEPENDS+=	tex-subfigure-[0-9]*:../../print/tex-subfigure
DEPENDS+=	tex-titlesec-[0-9]*:../../print/tex-titlesec
DEPENDS+=	tex-wasysym-[0-9]*:../../fonts/tex-wasysym
DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
DEPENDS+=	tex-rsfs-[0-9]*:../../fonts/tex-rsfs
DEPENDS+=	tex-eepic-[0-9]*:../../graphics/tex-eepic

USE_LANGUAGES=	# none
USE_TOOLS+=	gmake

.include "options.mk"

REPLACE_PYTHON+=		scripts/dblatex lib/dbtexmf/dblatex/xetex/*.py
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.3.2

SUBST_CLASSES+=		man
SUBST_MESSAGE.man=	Fixing man page installation path.
SUBST_STAGE.man=	pre-configure
SUBST_FILES.man=	setup.py
SUBST_SED.man+=		-e 's,share/man/man1,${PKGMANDIR}/man1,'
SUBST_SED.man+=		-e "s,'python','${PYTHONBIN}',"

do-test:
	cd ${WRKSRC}/tests/mathml && gmake

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
