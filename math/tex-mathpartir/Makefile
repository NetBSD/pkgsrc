# $NetBSD: Makefile,v 1.2 2019/12/06 19:07:33 markd Exp $

DISTNAME=	mathpartir
PKGNAME=	tex-${DISTNAME}-1.3.2
TEXLIVE_REV=	39864

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/mathpartir
COMMENT=	Typesetting sequences of math formulas, e.g. type inference rules
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
