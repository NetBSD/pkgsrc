# $NetBSD: Makefile,v 1.4 2022/09/01 10:42:19 markd Exp $

DISTNAME=	jlreq
PKGNAME=	tex-${DISTNAME}-2022
TEXLIVE_REV=	64072

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/jlreq
COMMENT=	Japanese document class based on requirements for Japanese text layout
LICENSE=	2-clause-bsd

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
