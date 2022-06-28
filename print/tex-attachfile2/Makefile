# $NetBSD: Makefile,v 1.5 2022/06/28 11:35:31 wiz Exp $

DISTNAME=	attachfile2
PKGNAME=	tex-${DISTNAME}-2.11
PKGREVISION=	3
TEXLIVE_REV=	52929

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/attachfile2
COMMENT=	Attach files into PDF
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hycolor-[0-9]*:../../print/tex-hycolor
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-infwarerr-[0-9]*:../../print/tex-infwarerr
DEPENDS+=	tex-kvoptions-[0-9]*:../../print/tex-kvoptions
DEPENDS+=	tex-ltxcmds-[0-9]*:../../print/tex-ltxcmds
DEPENDS+=	tex-pdfescape-[0-9]*:../../print/tex-pdfescape
DEPENDS+=	tex-pdftexcmds-[0-9]*:../../print/tex-pdftexcmds

USE_TOOLS+=	perl:run

REPLACE_PERL=	bin/pdfatfi

INSTALLATION_DIRS+=	bin

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/attachfile2/pdfatfi.pl ${WRKSRC}/bin/pdfatfi

.include "../../mk/bsd.pkg.mk"
