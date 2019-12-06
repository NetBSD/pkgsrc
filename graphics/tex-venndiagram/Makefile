# $NetBSD: Makefile,v 1.3 2019/12/06 20:04:42 markd Exp $

DISTNAME=	venndiagram
PKGNAME=	tex-${DISTNAME}-1.2
TEXLIVE_REV=	47952

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/venndiagram
COMMENT=	Creating Venn diagrams with TikZ
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
