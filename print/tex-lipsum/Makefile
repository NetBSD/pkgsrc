# $NetBSD: Makefile,v 1.2 2015/04/23 12:03:40 markd Exp $

DISTNAME=	lipsum
PKGNAME=	tex-${DISTNAME}-1.3
TEXLIVE_REV=	34800

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Easy access to the Lorem Ipsum dummy text
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
