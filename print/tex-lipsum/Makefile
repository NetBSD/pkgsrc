# $NetBSD: Makefile,v 1.7 2022/04/14 02:13:20 markd Exp $

DISTNAME=	lipsum
PKGNAME=	tex-${DISTNAME}-2.7
TEXLIVE_REV=	60561

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/lipsum
COMMENT=	Easy access to the Lorem Ipsum and other dummy texts
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
