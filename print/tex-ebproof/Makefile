# $NetBSD: Makefile,v 1.3 2020/01/18 23:34:02 rillig Exp $

DISTNAME=	ebproof
PKGNAME=	tex-${DISTNAME}-2.0
TEXLIVE_REV=	44392

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ebproof
COMMENT=	Formal proofs in the style of sequent calculus
LICENSE=	lppl-1.3c

DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
