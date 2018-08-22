# $NetBSD: Makefile,v 1.6 2018/08/22 09:46:16 wiz Exp $

DISTNAME=	thumbpdf
PKGNAME=	tex-${DISTNAME}-3.16
PKGREVISION=	3
TEXLIVE_REV=	34621

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Thumbnails for pdfTeX and dvips/ps2pdf
LICENSE=	lppl-1.3c

USE_TOOLS+=	perl:run
REPLACE_PERL=   bin/thumbpdf

INSTALLATION_DIRS+=	bin

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/thumbpdf/thumbpdf.pl ${WRKSRC}/bin/thumbpdf
	${RM} -rf ${WRKSRC}/texmf-dist/scripts

.include "../../mk/bsd.pkg.mk"
