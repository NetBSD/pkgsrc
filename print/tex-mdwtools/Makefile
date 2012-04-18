# $NetBSD: Makefile,v 1.1.1.1 2012/04/18 19:31:47 minskim Exp $

DISTNAME=	mdwtools
PKGNAME=	tex-${DISTNAME}-1.05.4
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Miscellaneous LaTeX tools by Mark Wooding
LICENSE=	gnu-gpl-v2

CONFLICTS=	teTeX-texmf<3.0nb35
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
