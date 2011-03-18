# $NetBSD: Makefile,v 1.29 2011/03/18 23:26:58 minskim Exp $

DISTNAME=	jadetex
PKGNAME=	tex-${DISTNAME}-3.13
PKGREVISION=	8
TEXLIVE_REV=	18835

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Macros supporting Jade DSSSL output

DEPENDS+=	tex-colortbl-[0-9]*:../../print/tex-colortbl
DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
DEPENDS+=	tex-fancyhdr-[0-9]*:../../print/tex-fancyhdr
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-lambda-[0-9]*:../../print/tex-lambda
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-marvosym-[0-9]*:../../fonts/tex-marvosym
DEPENDS+=	tex-passivetex>=1.25nb2:../../print/tex-passivetex
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-ulem-[0-9]*:../../print/tex-ulem
DEPENDS+=	web2c-[0-9]*:../../print/web2c

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=	"jadetex pdftex language.dat *jadetex.ini\\npdfjadetex pdftex language.dat *pdfjadetex.ini\\n"
TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/jadetex
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/pdfjadetex

.include "../../mk/bsd.pkg.mk"
