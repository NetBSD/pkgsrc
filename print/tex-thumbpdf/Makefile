# $NetBSD: Makefile,v 1.1 2015/04/27 07:22:44 markd Exp $

DISTNAME=	thumbpdf
PKGNAME=	tex-${DISTNAME}-3.16
TEXLIVE_REV=	34621

MAINTAINER=	pkgsrc-users@NetBSD,org
COMMENT=	Thumbnails for pdfTeX and dvips/ps2pdf
LICENSE=	lppl-1.3c

USE_TOOLS+=	perl:run
REPLACE_PERL=   bin/thumbpdf

CONFLICTS+=	teTeX-bin<=3.0nb56
CONFLICTS+=	teTeX-texmf<=3.0nb43

INSTALLATION_DIRS+=	bin

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/thumbpdf/thumbpdf.pl ${WRKSRC}/bin/thumbpdf
	${RM} -rf ${WRKSRC}/texmf-dist/scripts

.include "../../mk/bsd.pkg.mk"
