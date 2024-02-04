# $NetBSD: Makefile,v 1.6 2024/02/04 00:30:39 markd Exp $

DISTNAME=	jlreq
PKGNAME=	tex-${DISTNAME}-2023.67400
TEXLIVE_REV=	67400

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/jlreq
COMMENT=	Japanese document class based on requirements for Japanese text layout
LICENSE=	2-clause-bsd

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
