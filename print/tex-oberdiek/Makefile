# $NetBSD: Makefile,v 1.6 2011/10/26 21:53:54 minskim Exp $

DISTNAME=	oberdiek
PKGNAME=	tex-${DISTNAME}-2011
TEXLIVE_REV=	22180

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Bundle of packages submitted by Heiko Oberdiek

CONFLICTS+=	teTeX-texmf<=3.0nb13
CONFLICTS+=	texlive-pdftools<2011
DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=	p5-Getopt-Long-[0-9]*:../../devel/p5-Getopt-Long
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-etex-pkg-[0-9]*:../../print/tex-etex-pkg
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-ifluatex-[0-9]*:../../print/tex-ifluatex
DEPENDS+=	tex-ifxetex-[0-9]*:../../print/tex-ifxetex
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

REPLACE_PERL=	bin/pdfatfi

INSTALLATION_DIRS+=	bin

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/scripts/oberdiek/pdfatfi.pl ${WRKSRC}/bin/pdfatfi

.include "../../mk/bsd.pkg.mk"
