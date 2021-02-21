# $NetBSD: Makefile,v 1.1 2021/02/21 10:23:51 markd Exp $

DISTNAME=	gentombow
PKGNAME=	tex-${DISTNAME}-2020
TEXLIVE_REV=	56665

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/gentombow
COMMENT=	Generate Japanese-style crop marks
LICENSE=	modified-bsd

DEPENDS+=	tex-atbegshi-[0-9]*:../../print/tex-atbegshi
DEPENDS+=	tex-eso-pic-[0-9]*:../../print/tex-eso-pic

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
