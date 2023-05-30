# $NetBSD: Makefile,v 1.1 2023/05/30 11:51:26 markd Exp $

DISTNAME=	smartdiagram
PKGNAME=	tex-${DISTNAME}-0.3b
TEXLIVE_REV=	42781

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/smartdiagram
COMMENT=	Generate diagrams from lists
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-xstring-[0-9]*:../../print/tex-xstring

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
