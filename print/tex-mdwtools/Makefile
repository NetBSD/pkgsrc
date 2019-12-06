# $NetBSD: Makefile,v 1.3 2019/12/06 20:21:59 markd Exp $

DISTNAME=	mdwtools
PKGNAME=	tex-${DISTNAME}-1.05.4
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Miscellaneous LaTeX tools by Mark Wooding
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
