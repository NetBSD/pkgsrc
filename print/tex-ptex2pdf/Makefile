# $NetBSD: Makefile,v 1.1 2021/02/21 10:39:50 markd Exp $

DISTNAME=	ptex2pdf
PKGNAME=	tex-${DISTNAME}-20200520.0
TEXLIVE_REV=	55219

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ptex2pdf
COMMENT=	Convert Japanese TeX documents to PDF
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-luatex-[0-9]*:../../print/tex-luatex

REPLACE_TEXLUA=	bin/ptex2pdf

INSTALLATION_DIRS+=	bin

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/ptex2pdf/ptex2pdf.lua ${WRKSRC}/bin/ptex2pdf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
