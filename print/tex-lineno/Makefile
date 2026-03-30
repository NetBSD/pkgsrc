# $NetBSD: Makefile,v 1.8 2026/03/30 07:44:20 markd Exp $

DISTNAME=	lineno
PKGNAME=	tex-${DISTNAME}-5.9
TEXLIVE_REV=	78315

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/lineno
COMMENT=	Line numbers on paragraphs
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-kvoptions-[0-9]*:../../print/tex-kvoptions

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
