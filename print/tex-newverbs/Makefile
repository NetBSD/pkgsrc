# $NetBSD: Makefile,v 1.1 2022/08/21 15:12:37 wiz Exp $

DISTNAME=	newverbs
PKGNAME=	tex-${DISTNAME}-1.6
TEXLIVE_REV=	58256

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/p/newverbs/
COMMENT=	Define new versions of \verb, including short verb versions
LICENSE=	lppl-1.3c

# shortvrb
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
