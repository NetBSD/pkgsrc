# $NetBSD: Makefile,v 1.4 2021/02/15 02:02:15 markd Exp $

DISTNAME=	ebproof
PKGNAME=	tex-${DISTNAME}-2.1.1
TEXLIVE_REV=	57544

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ebproof
COMMENT=	Formal proofs in the style of sequent calculus
LICENSE=	lppl-1.3c

DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
