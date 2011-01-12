# $NetBSD: Makefile,v 1.1.1.1 2011/01/12 16:42:01 minskim Exp $

DISTNAME=	pdfcomment
PKGNAME=	tex-${DISTNAME}-2.1
TEXLIVE_REV=	20724

MAINTAINER=	minskim@NetBSD.org
COMMENT=	User-friendly interface to pdf annotations

DEPENDS+=	tex-datetime-[0-9]*:../../print/tex-datetime
DEPENDS+=	tex-hyperref>=6.81p:../../print/tex-hyperref
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-marginnote-[0-9]*:../../print/tex-marginnote
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
