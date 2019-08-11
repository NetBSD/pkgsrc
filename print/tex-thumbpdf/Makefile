# $NetBSD: Makefile,v 1.8 2019/08/11 13:22:43 wiz Exp $

DISTNAME=	thumbpdf
PKGNAME=	tex-${DISTNAME}-3.17
PKGREVISION=	1
TEXLIVE_REV=	48625

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
