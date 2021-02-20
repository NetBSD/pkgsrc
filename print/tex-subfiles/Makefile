# $NetBSD: Makefile,v 1.6 2021/02/20 10:48:19 markd Exp $

DISTNAME=	subfiles
PKGNAME=	tex-${DISTNAME}-2.2
TEXLIVE_REV=	56977

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/subfiles
COMMENT=	Individual typesetting of subfiles of a "main" document
LICENSE=	lppl-1.3c

DEPENDS+=	tex-import-[0-9]*:../../print/tex-import

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
