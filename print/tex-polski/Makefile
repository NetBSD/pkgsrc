# $NetBSD: Makefile,v 1.2 2017/06/21 11:45:57 markd Exp $

DISTNAME=	polski
PKGNAME=	tex-${DISTNAME}-1.3.4
TEXLIVE_REV=	44213

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/polski
COMMENT=	Typeset Polish documents with LaTeX and Polish fonts
LICENSE=	lppl-1.2

DEPENDS+=	tex-pl-[0-9]*:../../fonts/tex-pl
DEPENDS+=	tex-hyphen-polish-[0-9]*:../../print/tex-hyphen-polish

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
