# $NetBSD: Makefile,v 1.3 2019/12/06 20:21:29 markd Exp $

DISTNAME=	fvextra
PKGNAME=	tex-${DISTNAME}-1.4
TEXLIVE_REV=	49947

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/fvextra
COMMENT=	Extensions and patches for fancyvrb
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-fancyvrb-[0-9]*:../../print/tex-fancyvrb
DEPENDS+=	tex-lineno-[0-9]*:../../print/tex-lineno
DEPENDS+=	tex-upquote-[0-9]*:../../print/tex-upquote

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
