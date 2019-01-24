# $NetBSD: Makefile,v 1.3 2019/01/24 09:19:11 jperkin Exp $

DISTNAME=	mathalfa
PKGNAME=	tex-${DISTNAME}-1.10
TEXLIVE_REV=	47575

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/mathalfa
COMMENT=	General package for loading maths alphabets in LaTeX
LICENSE=	lppl-1.3c

TEXLIVE_USE_CTAN=	yes

DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
