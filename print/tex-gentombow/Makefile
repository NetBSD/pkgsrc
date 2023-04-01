# $NetBSD: Makefile,v 1.2 2023/04/01 11:09:27 markd Exp $

DISTNAME=	gentombow
PKGNAME=	tex-${DISTNAME}-2022
TEXLIVE_REV=	64333

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/gentombow
COMMENT=	Generate Japanese-style crop marks
LICENSE=	modified-bsd

DEPENDS+=	tex-atbegshi-[0-9]*:../../print/tex-atbegshi
DEPENDS+=	tex-eso-pic-[0-9]*:../../print/tex-eso-pic

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
