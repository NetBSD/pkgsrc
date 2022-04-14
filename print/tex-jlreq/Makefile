# $NetBSD: Makefile,v 1.3 2022/04/14 01:49:00 markd Exp $

DISTNAME=	jlreq
PKGNAME=	tex-${DISTNAME}-2021.63004
TEXLIVE_REV=	63004

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/jlreq
COMMENT=	Japanese document class based on requirements for Japanese text layout
LICENSE=	2-clause-bsd

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
