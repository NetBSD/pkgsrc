# $NetBSD: Makefile,v 1.1.1.1 2012/05/08 18:28:38 minskim Exp $

DISTNAME=	bbold
PKGNAME=	tex-${DISTNAME}-1.01
CATEGORIES=	fonts
TEXLIVE_REV=	17187

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Sans serif blackboard bold
LICENSE=	modified-bsd

DEPENDS+=	tex-bbold-type1-[0-9]*:../../fonts/tex-bbold-type1
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
