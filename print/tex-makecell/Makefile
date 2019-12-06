# $NetBSD: Makefile,v 1.2 2019/12/06 20:21:57 markd Exp $

DISTNAME=	makecell
PKGNAME=	tex-${DISTNAME}-0.1e
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/makecell
COMMENT=	Tabular column heads and multilined cells
LICENSE=	lppl-1.3c

DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
