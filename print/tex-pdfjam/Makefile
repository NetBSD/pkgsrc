# $NetBSD: Makefile,v 1.2 2026/04/03 23:40:00 markd Exp $

DISTNAME=	pdfjam
PKGNAME=	tex-${DISTNAME}-4.3
TEXLIVE_REV=	78572

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pdfjam
COMMENT=	Shell script interface to pdfpages
LICENSE=	gnu-gpl-v2

DEPENDS+=       tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=       tex-pdfpages-[0-9]*:../../print/tex-pdfpages

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/pdfjam/pdfjam ${WRKSRC}/bin/pdfjam
	${RM} -rf ${WRKSRC}/texmf-dist/scripts

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
