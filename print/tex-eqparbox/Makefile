# $NetBSD: Makefile,v 1.2 2017/10/21 03:38:01 markd Exp $

DISTNAME=	eqparbox
PKGNAME=	tex-${DISTNAME}-4.1
TEXLIVE_REV=	45215

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/eqparbox
COMMENT=	Create equal-widthed parboxes
LICENSE=	lppl-1.3c

DEPENDS+=	tex-environ-[0-9]*:../../print/tex-environ
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
