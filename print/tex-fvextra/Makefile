# $NetBSD: Makefile,v 1.1 2018/01/18 10:29:25 markd Exp $

DISTNAME=	fvextra
PKGNAME=	tex-${DISTNAME}-1.3.1
TEXLIVE_REV=	44787

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/fvextra
COMMENT=	Extensions and patches for fancyvrb
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-fancyvrb-[0-9]*:../../print/tex-fancyvrb
DEPENDS+=	tex-lineno-[0-9]*:../../print/tex-lineno
DEPENDS+=	tex-upquote-[0-9]*:../../print/tex-upquote

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
