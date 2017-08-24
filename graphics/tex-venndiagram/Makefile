# $NetBSD: Makefile,v 1.1 2017/08/24 02:21:17 markd Exp $

DISTNAME=	venndiagram
PKGNAME=	tex-${DISTNAME}-1.1
TEXLIVE_REV=	40058

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/venndiagram
COMMENT=	Creating Venn diagrams with TikZ
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
