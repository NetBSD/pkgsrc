# $NetBSD: Makefile,v 1.47 2026/10/10 10:51:07 adam Exp $

DISTNAME=	dblatex3-0.3.12
PKGNAME=	${DISTNAME:S/tex3/tex/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dblatex/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dblatex.sourceforge.net/
COMMENT=	DocBook to LaTeX Publishing
LICENSE=	gnu-gpl-v2

EGG_NAME=	${DISTNAME:S/tex3/tex/}

DEPENDS+=	ImageMagick>=0:../../graphics/ImageMagick
DEPENDS+=	tex-latex-bin>=0:../../print/tex-latex-bin
DEPENDS+=	makeindexk>=0:../../textproc/makeindexk
DEPENDS+=	libxslt>=0:../../textproc/libxslt
DEPENDS+=	texlive-collection-latex>=0:../../meta-pkgs/texlive-collection-latex
DEPENDS+=	tex-iftex>=1.0d:../../print/tex-iftex
DEPENDS+=	tex-anysize>=0:../../print/tex-anysize
DEPENDS+=	tex-appendix>=0:../../print/tex-appendix
DEPENDS+=	tex-bookmark>=0:../../print/tex-bookmark
DEPENDS+=	tex-changebar>=0:../../print/tex-changebar
DEPENDS+=	tex-fancybox>=0:../../print/tex-fancybox
DEPENDS+=	tex-fancyvrb>=0:../../print/tex-fancyvrb
DEPENDS+=	tex-float>=0:../../print/tex-float
DEPENDS+=	tex-footmisc>=0:../../print/tex-footmisc
DEPENDS+=	tex-jknapltx>=0:../../print/tex-jknapltx
DEPENDS+=	tex-listings>=0:../../print/tex-listings
DEPENDS+=	tex-multirow>=0:../../print/tex-multirow
DEPENDS+=	tex-overpic>=0:../../print/tex-overpic
DEPENDS+=	tex-pdflscape>=0:../../print/tex-pdflscape
DEPENDS+=	tex-pdfpages>=0:../../print/tex-pdfpages
DEPENDS+=	tex-rotating>=0:../../print/tex-rotating
DEPENDS+=	tex-stmaryrd>=0:../../fonts/tex-stmaryrd
DEPENDS+=	tex-subfigure>=0:../../print/tex-subfigure
DEPENDS+=	tex-titlesec>=0:../../print/tex-titlesec
DEPENDS+=	tex-wasysym>=0:../../fonts/tex-wasysym
DEPENDS+=	tex-ec>=0:../../fonts/tex-ec
DEPENDS+=	tex-rsfs>=0:../../fonts/tex-rsfs
DEPENDS+=	tex-eepic>=0:../../graphics/tex-eepic

USE_LANGUAGES=	# none
USE_TOOLS+=	gmake:test

# As of 0.3.12, needs imp module which has been removed in Python 3.12.
PYTHON_VERSIONS_ACCEPTED=	311

.include "options.mk"

REPLACE_PYTHON+=	lib/dbtexmf/dblatex/xetex/*.py
REPLACE_PYTHON+=	scripts/dblatex

SUBST_CLASSES+=		man
SUBST_MESSAGE.man=	Fixing man page installation path.
SUBST_STAGE.man=	pre-configure
SUBST_FILES.man=	setup.py
SUBST_SED.man+=		-e 's,share/man/man1,${PKGMANDIR}/man1,'
SUBST_SED.man+=		-e "s,'python','${PYTHONBIN}',"

do-test:
	cd ${WRKSRC}/tests/mathml && ${GMAKE}

.include "../../lang/python/application.mk"
# wheel.mk doesn't install "dblatex" script
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
