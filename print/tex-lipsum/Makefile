# $NetBSD: Makefile,v 1.6 2021/06/05 04:00:34 markd Exp $

DISTNAME=	lipsum
PKGNAME=	tex-${DISTNAME}-2.3
TEXLIVE_REV=	58123

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/lipsum
COMMENT=	Easy access to the Lorem Ipsum dummy text
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
