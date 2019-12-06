# $NetBSD: Makefile,v 1.5 2019/12/06 20:23:15 markd Exp $

DISTNAME=	shadethm
PKGNAME=	tex-${DISTNAME}-20120818
TEXLIVE_REV=	20319

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Theorem environments that are shaded
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
