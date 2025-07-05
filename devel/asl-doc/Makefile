# $NetBSD: Makefile,v 1.1 2025/07/05 12:12:14 hauke Exp $

DISTNAME=	asl-current-142-bld290
PKGNAME=	asl-doc-1.42.290
CATEGORIES=	devel
MASTER_SITES=	http://john.ccac.rwth-aachen.de:8000/ftp/as/source/c_version/

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://john.ccac.rwth-aachen.de:8000/as
COMMENT=	Portable macro cross assembler documentation
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/asl-current

# The docs build is entangled with making some objects, which we end
# up not using
USE_LANGUAGES=	c

USE_TOOLS=	gmake

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-babel-[0-9]*:../../print/tex-babel
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-german-[0-9]*:../../print/tex-german
DEPENDS+=	texlive-collection-fontsrecommended-[0-9]*:../../meta-pkgs/texlive-collection-fontsrecommended
DEPENDS+=	texlive-collection-latexrecommended-[0-9]*:../../meta-pkgs/texlive-collection-latexrecommended

DOCDIR=		share/doc/asl

INSTALLATION_DIRS+=	${DOCDIR}

pre-configure:
	${CP} ${FILESDIR}/Makefile.def.pkgsrc ${WRKSRC}/Makefile.def
	mkdir ${WRKSRC}/objects

.include "../../mk/bsd.pkg.mk"
