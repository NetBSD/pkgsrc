# $NetBSD: Makefile,v 1.2 2019/01/27 08:55:41 markd Exp $

DISTNAME=	abntex2
PKGNAME=	tex-${DISTNAME}-1.9.7
TEXLIVE_REV=	49248

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/abntex2
COMMENT=	Typeset technical and scientific Brazilian documents based on ABNT rules
LICENSE=	lppl-1.3c

DEPENDS+=	tex-enumitem>=3.5.2:../../print/tex-enumitem
DEPENDS+=	tex-hyperref>=6.83m:../../print/tex-hyperref
DEPENDS+=	tex-memoir>=3.7e:../../print/tex-memoir
DEPENDS+=	tex-textcase>=0.07:../../print/tex-textcase

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
