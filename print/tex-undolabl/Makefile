# $NetBSD: Makefile,v 1.3 2019/12/06 20:23:38 markd Exp $

DISTNAME=	undolabl
PKGNAME=	tex-${DISTNAME}-1.0l
TEXLIVE_REV=	36681

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Overriding of existing labels
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
