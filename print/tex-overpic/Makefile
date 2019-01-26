# $NetBSD: Makefile,v 1.5 2019/01/26 02:48:28 markd Exp $

DISTNAME=	overpic
PKGNAME=	tex-${DISTNAME}-1.2
TEXLIVE_REV=	48550

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/overpic
COMMENT=	Combine LaTeX commands over included graphics
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
