# $NetBSD: Makefile,v 1.3 2016/06/16 04:06:13 markd Exp $

DISTNAME=	pdfcomment
PKGNAME=	tex-${DISTNAME}-2.3b
TEXLIVE_REV=	40166

MAINTAINER=	minskim@NetBSD.org
COMMENT=	User-friendly interface to pdf annotations
LICENSE=	lppl-1.3c

DEPENDS+=	tex-datetime-[0-9]*:../../print/tex-datetime
DEPENDS+=	tex-hyperref>=6.81p:../../print/tex-hyperref
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-marginnote-[0-9]*:../../print/tex-marginnote
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
