# $NetBSD: Makefile,v 1.2 2022/09/01 10:39:36 markd Exp $

DISTNAME=	hypdoc
PKGNAME=	tex-${DISTNAME}-1.17
TEXLIVE_REV=	63808

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/hypdoc
COMMENT=	Hyper extensions for doc.sty
LICENSE=	lppl-1.3c

DEPENDS+=	tex-atveryend-[0-9]*:../../print/tex-atveryend

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
