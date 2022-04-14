# $NetBSD: Makefile,v 1.5 2022/04/14 03:20:20 markd Exp $

DISTNAME=	polski
PKGNAME=	tex-${DISTNAME}-1.3.6
TEXLIVE_REV=	60322

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/polski
COMMENT=	Typeset Polish documents with LaTeX and Polish fonts
LICENSE=	lppl-1.2

DEPENDS+=	tex-hyphen-polish-[0-9]*:../../print/tex-hyphen-polish
DEPENDS+=	tex-pl-[0-9]*:../../fonts/tex-pl

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
