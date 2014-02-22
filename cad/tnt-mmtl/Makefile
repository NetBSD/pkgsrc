# $NetBSD: Makefile,v 1.25 2014/02/22 09:19:24 obache Exp $
#

DISTNAME=	tnt-1.2.2
PKGNAME=	${DISTNAME:S/tnt/tnt-mmtl/}
PKGREVISION=	11
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mmtl/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://mmtl.sourceforge.net/
COMMENT=	Multilayer Multiconductor Transmission Line 2-D and 2.5-D simulator

BUILD_DEPENDS+=	latex2html-[0-9]*:../../textproc/latex2html
BUILD_DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
BUILD_DEPENDS+=	tex-fancyhdr-[0-9]*:../../print/tex-fancyhdr
BUILD_DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
BUILD_DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
BUILD_DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
BUILD_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

PKG_INSTALLATION_TYPES= overwrite pkgviews

GNU_CONFIGURE=	YES
USE_TOOLS+=	aclocal autoconf automake gmake
USE_LANGUAGES=	c c++ fortran77

# without this, configure ends up using 'gcc -E' for CPP and
# passing that down via an environment variable to f2c-f77 which
# in turn ends up feeding a .F file to gcc -E that fails due to
# fortran not being a configured language.  This is what happens on
# a stock NetBSD-5.1 install.
CONFIGURE_ENV+=	CPP=${CPP}

post-patch:
	${MV} ${WRKSRC}/tnt ${WRKSRC}/tnt-mmtl
	cd ${WRKSRC}/bem && aclocal
	cd ${WRKSRC}/bem && automake --add-missing --copy --force-missing
	cd ${WRKSRC}/bem && autoconf

.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/tcl-itcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../x11/tk-BWidget/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
