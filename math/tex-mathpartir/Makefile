# $NetBSD: Makefile,v 1.3 2020/01/18 23:32:53 rillig Exp $

DISTNAME=	mathpartir
PKGNAME=	tex-${DISTNAME}-1.3.2
TEXLIVE_REV=	39864

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/mathpartir
COMMENT=	Typesetting sequences of math formulas, e.g. type inference rules
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
