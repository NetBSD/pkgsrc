# $NetBSD: Makefile,v 1.3 2023/04/02 11:14:57 markd Exp $

DISTNAME=	hypdoc
PKGNAME=	tex-${DISTNAME}-1.18
TEXLIVE_REV=	65678

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/hypdoc
COMMENT=	Hyper extensions for doc.sty
LICENSE=	lppl-1.3c

DEPENDS+=	tex-atveryend-[0-9]*:../../print/tex-atveryend

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
