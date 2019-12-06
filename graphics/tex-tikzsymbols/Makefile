# $NetBSD: Makefile,v 1.7 2019/12/06 20:04:41 markd Exp $

DISTNAME=	tikzsymbols
PKGNAME=	tex-${DISTNAME}-4.10c
TEXLIVE_REV=	49975

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/tikzsymbols
COMMENT=	Some symbols created using TikZ
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
