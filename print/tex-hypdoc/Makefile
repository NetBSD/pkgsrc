# $NetBSD: Makefile,v 1.4 2024/02/04 00:15:23 markd Exp $

DISTNAME=	hypdoc
PKGNAME=	tex-${DISTNAME}-1.19
TEXLIVE_REV=	68661

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/hypdoc
COMMENT=	Hyper extensions for doc.sty
LICENSE=	lppl-1.3c

DEPENDS+=	tex-atveryend-[0-9]*:../../print/tex-atveryend

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
