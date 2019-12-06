# $NetBSD: Makefile,v 1.4 2019/12/06 20:19:08 markd Exp $

DISTNAME=	chessfss
PKGNAME=	tex-${DISTNAME}-1.2a
PKGREVISION=	1
TEXLIVE_REV=	19440

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/chessfss
COMMENT=	LaTeX package to handle chess fonts
LICENSE=	lppl-1.3c

DEPENDS+=	tex-lambda-lists-[0-9]*:../../print/tex-lambda-lists
DEPENDS+=	tex-skaknew-[0-9]*:../../print/tex-skaknew
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
